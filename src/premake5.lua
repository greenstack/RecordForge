project "RecordForge"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"

    targetdir ("bin/%{cfg.buildcfg}")
    objectdir ("obj/%{cfg.buildcfg}")

    files
    {
        "src/**.hpp",
        "src/**.cpp",
    }

    filter "action:xcode4"
        systemversion "13.1"
        externalincludedirs {
            "src/vendor",
        }

    filter "configurations:Debug"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        runtime "Release"
        optimize "on"
        symbols "off"