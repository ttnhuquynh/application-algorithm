/*
    Đây là comment dạng khối.
    Những gì viết trong này sẽ được bỏ qua khi biên dịch.
*/
// Đây là comment dòng đơn.

#include <iostream> // Khai báo thư viện, iostream là thư viện nhập xuất.
#define program_name "example" // Khai báo định nghĩa cho tên program_name

using namespace std; // Khai báo không gian tên.

int main() // Hàm thực thi.
{  
    int value;
    cout << "Nhap gia tri: ";
    cin >> value;
    cout << "Hello World! " << value << endl; // Một lệnh đơn.

    return 0; // Trả ra giá trị cho hàm, sẽ học ở một bài khác.  
} 
