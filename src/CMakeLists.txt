add_library(simpleLibrary
    User.cpp
    UserData.cpp
    UserTxtData.cpp
    loginpage.cpp
    homepage.cpp
    ui.cpp
    UserBinData.cpp
    Task.cpp
    OpenaiAPI.cpp
    main.cpp
)

find_library(M_LIB m)
target_link_libraries(simpleLibrary ${M_LIB})

find_package( CURL REQUIRED )
target_link_libraries( simpleLibrary CURL::libcurl )
