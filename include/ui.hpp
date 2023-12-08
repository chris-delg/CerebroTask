#ifndef UI_HPP
#define UI_HPP

#include "page.hpp"
#include "loginpage.hpp"
#include "homepage.hpp"
#include "UserData.hpp"
#include "UserBinData.hpp"
#include "UserTxtData.hpp"

using namespace std;

class UI {
    private:
        //Page * pages[2]; // array of page pointers
        LoginPage * login; 
        HomePage * home; 
        
        UserData * user_data;
        int ui_size = 2; //number of pages expected in the UI
        int curr_page = 0; // tracks the current page the UI is on. 0 = login, 1 = home
    public:
        UI();
        ~UI();
        void changePage(int new_page);
        int getPageNum() {return curr_page; };
        LoginPage * getLoginPage() {return login; };
        HomePage * getHomePage() {return home; };
        UserData * getData() {return user_data; };
        int size() {return ui_size; };
};

#endif /* UI_HPP */