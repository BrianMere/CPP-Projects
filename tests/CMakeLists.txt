set(${TEST_SOURCE_DIR} .)

foreach( testsourcefile ${TEST_SOURCE_DIR})
    get_filename_component( testname ${testsourcefile} NAME_WE )
    add_executable( ${testname} ${testsourcefile} )
endforeach( testsourcefile ${TEST_SOURCE_DIR})