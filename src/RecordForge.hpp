#pragma once

// STL includes
#include <string>
#include <unordered_set>

// External includes
#include "vendor/csv-parser/csv.hpp"

namespace RF {
enum class ForgeResult
{
    Success,
    // Permissions failure
    Failure_Permission,
    // CSV formatting failure
    Failure_InvalidFormat,
    // CSV file could not open
    Failure_CouldNotOpen,
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
    RecordForge(const std::string& path, const std::unordered_set<std::string>& skipColumns, std::ostream& output) :
        mSkipColumns(skipColumns),
        mPath(path)
    {}
    
    /**
     * Runs the full pipeline.
     *
     * @return The result of the pipeline.
     */
    ForgeResult Forge();
private:
    const std::unordered_set<std::string> mSkipColumns;
    const std::string_view mPath;
};
}
