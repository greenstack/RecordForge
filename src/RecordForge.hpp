#pragma once

// STL includes
#include <string>
#include <unordered_set>

// External includes
#include <csv-parser/csv.hpp>

namespace rf {
enum class ForgeResult
{
    Success,
    // Permissions failure
    Failure_Permission,
    // CSV formatting failure
    Failure_InvalidFormat,
    // Unknown/other failure
    Failure_Unknown
};
    
/**
 * The main entry point for all your record forge needs.
 */
class RecordForge
{
public:
    // TODO: Include a parameter for the processor type (Lua, Python) via enum
    // OR a reference to a processor.
    explicit RecordForge(const std::string& path, const std::unordered_set<std::string>& skipColumns);
    
    /**
     * Runs the full pipeline.
     */
    ForgeResult Forge();
private:
    std::unordered_set<std::string> mSkipColumns;
    std::string path;
};
}
