#include <iostream>
#include <netdb.h>
#include <arpa/inet.h>


using std::cout;
using std::endl;

#define PORT    80      // HTTPのポート番号

int main(int argc, char *argv[]) {
    struct in_addr addr;
    struct hostent *hp;

    // 入力数が不正な場合
    if (argc != 2) {
        cout << "入力数が不正です。" << endl;
        exit(1);
    }
    
    // 入力されたホスト名が存在しない場合
    if ((hp = gethostbyname(argv[1])) == NULL) {
        herror("gethostbyname");
        exit(1);
    }

    addr.s_addr = **(unsigned int **)(hp->h_addr_list);
    cout << inet_ntoa(addr) << endl;

    return 0;
}