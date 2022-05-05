
set(Datastructs_INCLUDE_DIR "include")

# set(Datastructs_INCLUDE_FILES 
#         "${Datastructs_INCLUDE_DIR}/utilities/datastructs/range.h"
# )

add_library(datastructs INTERFACE)
target_include_directories(datastructs INTERFACE "${Datastructs_INCLUDE_DIR}")

add_library(Utilities::Datastructs ALIAS datastructs)