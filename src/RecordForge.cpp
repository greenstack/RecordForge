#include "RecordForge.hpp"

using namespace RF;

ForgeResult RecordForge::Forge()
{
    using namespace csv;

    // Open the CSV file
    try {
        CSVReader reader = CSVReader(mPath);
        
        std::vector columnNames = reader.get_col_names();
        std::vector<std::string> readColumns;
        
        // Get the columns that we will always read and never skip
        for (const auto& column : columnNames)
        {
            // Check if column is to be skipped
            if (mSkipColumns.find(column) == mSkipColumns.end())
            {
                readColumns.push_back(column);
            }
        }

        auto writer = make_csv_writer(std::cout);
        // For each row
        for (const auto& row : reader)
        {
            std::vector<std::string> rowStr;
            // Foreach column
            for (const auto& column : readColumns)
            {
                
                // Process the data
                //std::cout << "Value for `" << column << "` is `" << row[column].get() << "`\n";
                // Append the data to the row
                rowStr.push_back(row[column].get());
            }
            writer << rowStr;
        }
    }
    catch (const std::runtime_error& err)
    {
        // TODO: Figure out how the errors are reported here.
        return ForgeResult::Failure_Unknown;
    }
    
    // Write the rows to a new CSV file (start by printing it to the console)
    return ForgeResult::Failure_Unknown;
}
