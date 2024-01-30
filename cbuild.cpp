#define CBUILD_IMPLEMENTATION
#include "cbuild.h"

void build_testbed(char** argv) {
	CBuild cbuild("gcc");
	cbuild
		.out("bin", "testbed")
		.flags({"-Wall", "-Wextra"})
		.inc_paths({"src/"})
		.lib_paths({"bin/"})
		.libs({"pe"})
		.src({"testbed/main.c"})
		.build()
		.clean()
		.run(argv);
}

void build_tests(char** argv) {
	CBuild cbuild("gcc");
	cbuild
		.out("bin", "testbed")
		.flags({"-Wall", "-Wextra"})
		.inc_paths({"src/"})
		.lib_paths({"bin/"})
		.libs({"pe"})
		.src({"tests/main.c"})
		.build()
		.clean()
		.run(argv);
}

void compile_externals() {
	CBuild cbuild("gcc");
	cbuild
		.inc_paths({"src/", "src/external/glew/include/"})
		.src({
			 "src/pe_glfw.c",
			 "src/external/glew/src/glew.c",
			 "src/external/glew/src/glewinfo.c",
			 "src/external/glew/src/visualinfo.c",
		})
		.compile();
}

void build_engine() {
	compile_externals();

	CBuild cbuild("gcc");
	cbuild
		.out("bin", "libpe.a")
		.flags({"-Wall", "-Wextra"})
		.inc_paths({"src/"})
		.src({
			"src/allocators/trace_allocator.c"
		})
		.objs({
			"src/pe_glfw.o",
			 "src/external/glew/src/glew.o",
			 "src/external/glew/src/glewinfo.o",
			 "src/external/glew/src/visualinfo.o",
		})
		.build_static_lib()
		.clean();
}

void print_usage() {
	std::cout << "[Usage]: ./cbuild [options]" << std::endl;
	std::cout << "\t--engine: Builds the engine\n";
	std::cout << "\t--testbed: Builds testbed\n";
	std::cout << "\t--tests: Builds all tests\n";
}

int main(int argc, char** argv) {
	cbuild_rebuild(argc, argv);
	std::vector<std::string> args(argv, argv + argc);

	args.erase(args.begin());

	if (!args.size())
		print_usage();

	for (const std::string& arg : args) {
		if (arg == "--engine")
			build_engine();
		else if (arg == "--testbed")
			build_testbed(argv);
		else if (arg == "--tests")
			build_tests(argv);
		else
			print_usage();
	}
}
