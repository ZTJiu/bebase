package(default_visibility = ["//visibility:public"])

cc_library(
    name = "slog",
    includes = ["include"],
    copts = [
        "-g",
        "-O2",
        "-Wall",
    "-Wno-unused-result",
    ],
    linkopts = [
        "-lrt",
    ],
    nocopts = "-fPIC",
    linkstatic = 1,
    srcs = glob([
        "include/*.h",
    ]),
    deps = [
        "@third_party//log4cplus-200-rc1",
  ],
)

cc_test(
    name = "test",
    includes = ["include"],
    copts = [
        "-g",
        "-O2",
        "-Wall",
        "-Wno-deprecated-declarations",
    ],
    linkopts = [
        "-lrt",
    ],
    srcs = [
        "include/slog.h",
        "test/main.cc",
    ],
    deps = [
        ":slog",
    ],
)
