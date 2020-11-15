#include <iostream>
#include <istream>
#include <ios>
#include <limits>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <time.h>


#include "lib.h"


void PrintNameFunc(void){
    
    PrintName *PName_p;

    cout << "請輸入兩個名子:\n" ;
    PName_p = new PrintName();
    cin >> PName_p->name1 >> PName_p->name2;
    //cin >> name1 >> name2 ;
    
    //cout << "pls enter a line data:\n" ;
    //cin.getline(str,50);
    
    PName_p->print_name();
    
    delete PName_p;
    
    
}


void CalInvestFunc(void){
    
    InvestCal *investCal_p;

    cout << "請輸入 初期資本,年利率,年期\n";
    investCal_p = new InvestCal();
    
    cin >> investCal_p->capital >> investCal_p->yearRate >> investCal_p->years;
    investCal_p->yearRate = investCal_p->yearRate / 100;

    investCal_p->InitCapInvestCal();
    
    cout << "期末本利和在 " << investCal_p->years << " 年後是\n";
    cout << investCal_p->sum << endl;
    
    cout << "請輸入 定期資本,年利率,年期\n";
    cin >> investCal_p->capital >> investCal_p->yearRate >> investCal_p->years;
    investCal_p->yearRate = investCal_p->yearRate / 100;
    
    investCal_p->PeriodCapInvestCal();
    
    cout << "全部投入資本在 " << investCal_p->years << " 年後是\n";
    cout << investCal_p->capsum << endl;
    cout << "終期本利和在 " << investCal_p->years << " 年後是\n";
    cout << investCal_p->sum << endl;
    
    delete investCal_p;

    
}


void EnDecryptFunc(void){
    
    Encrypt   *encryptor_p;
    char cstr[1024+1];
    string s;
    
    
    encryptor_p = new Encrypt();
    //印出Encrypt初始完的內部EnstrTable
    cout << "印出Encrypt初始完的內部EnstrTable" << endl;
    cout << encryptor_p->EnstrTable << endl;

    
    //cin.getline() automatically add '\0' at the end of string
    //cin.getline(cstr,sizeof(cstr),'\n');
    //cin.getline(cstr,sizeof(cstr)) default line end char is '\n'
    cout << "請輸入要被加密的字串：" << endl;
    
    cin.getline(cstr,sizeof(cstr),'\n');
    //cout << sizeof(std::ios_base::iostate) << endl;
    //printf("cin rdstate:%x\n",cin.rdstate());
    
    //only count for get(),getline() etc.. ,useless for cin >> cstr
    //printf("cin gcount:%ld\n",cin.gcount());
    
    //cout << "原輸入字串：" << endl;
    //cout << cstr << endl;
    s = cstr;
    //對原輸入字串s，以EnstrTable加密表做加密，再輸出加密後的字串存回s中
    //s只能為小寫英文字，其他不加密
    s = encryptor_p->enstring(s);
    cout << "加密後字串：" << endl;
    cout << s << endl;
    
    
    /*
     
     //getline() need <string>
     getline(cin, s, '\n');
     cout << s << endl;
     s = encryptor_p->enstring(s);
     cout << s << endl;
     
     
     cin.get(cstr,sizeof(cstr));
     cout << cstr << endl;
     s = cstr;
     s = encryptor_p->enstring(s);
     cout << s << endl;
     
     
     ch = getchar();
     //ch = getc(stdin);
     s = "";
     s += ch;
     s = encryptor_p->enstring(s);
     cout << s << endl;
     
     
     cin >> s;
     //scanf("%s", cstr);
     s = encryptor_p->enstring(s);
     cout << s << endl;
     
     */
    
    cout << "解密後字串：" << endl;
    cout << encryptor_p->destring(s) << endl;
    
    delete encryptor_p;
    
}


//類別繼承測試
class Point2D {
    public:
        //Point2D();
        Point2D(int x=0, int y=0);
        void print2D(void){
            cout << "m_x=" << m_x << endl;
            cout << "m_y=" << m_y << endl;
        }
    private:
        int m_x;
        int m_y;
};

/*
Point2D::Point2D(){
    //cout << "Point2D()" <<endl;

    m_x = 1;
    m_y = 1;
}
*/

Point2D::Point2D(int x, int y){
    //cout << "Point2D(int x, int y)" <<endl;

    m_x = x;
    m_y = y;
}

class Point3D : public Point2D {

    public:
        //Point3D();
        Point3D(int x=0, int y=0, int z=0);
        //~Point3D();
        void print3D(void){
            print2D();
            cout << "m_z=" << m_z << endl;
        }

    private:
        int m_z;
};

/*
Point3D::Point3D(): Point2D(){
    //cout << "Point3D()" <<endl;
    m_z = 1;
}
*/

Point3D::Point3D(int x, int y, int z) : Point2D(x,y) {
    //cout << "Point3D(int x, int y, int z)" <<endl;

    //Point2D(x, y);
    m_z = z;
}
//類別繼承測試ＥＮＤ


int main(int argc, char *argv[]) {

	int c;
    
    
	cout << "請選擇功能：\n" ;
    cout << "0.離開\n" ;
	cout << "1.列印名子\n" ;
	cout << "2.投資計算\n" ;
	cout << "3.隨機值產生\n" ;
	cout << "4.加解密字串\n" ;
    cout << "5.類別繼承測試\n" ;

    
	cin >> c ;
    //cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //cin.ignore(numeric_limits<streamsize>::max());
    

	switch(c){

        case 0:
            
            break;
            
		case 1:

            PrintNameFunc();
	    cout << "增加MSG by coworkers\n" ;
	    cout << "增加MSG_2 by coworkers\n" ;
	    cout << "增加MSG_3 by coworkers\n" ;

			break;

		case 2:

            CalInvestFunc();

			break;

		case 3:
			// rand()=0~RAND_MAX
			printf("The RAND_MAX is %d\n", RAND_MAX);
			srand(time(0));

			printf("The Random Number of 1~100 is %d\n", ((rand()%100)+1) );
			printf("The Random Number of 1~100 is %d\n", ((rand()%100)+1) );
			printf("The Random Number of 1~100 is %d\n", ((rand()%100)+1) );

			break;

		case 4:

            EnDecryptFunc();
            
			break;


		case 5:
            //要加{}是避免Ｃ++ C14產生crosses initialization編譯錯誤
            //在Ｃ和Ｃ++ C11不會編譯錯誤，所以是C14特別嚴格
            //增加一個scope 讓Ｃ++ C14認為可以在裡面宣告一個初始變量
            {
                Point3D p1(1,2,3),p2,p3(1),p4(1,2);
                
                p1.print3D();
                p2.print3D();
                p3.print3D();
                p4.print3D();

            }
			break;

            
		default:

            //printf("選擇錯誤,請在試一次\n");
			cout << "選擇錯誤,請在試一次\n" ;

	}
    
    

	return 0;


}

