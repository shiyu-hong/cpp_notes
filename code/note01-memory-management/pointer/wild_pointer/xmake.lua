add_rules("mode.debug", "mode.release")
add_rules("plugin.compile_commands.autoupdate", {outputdir = ".vscode"})

target("wild_pointer")
    set_kind("binary")
    add_files("src/*.cpp")