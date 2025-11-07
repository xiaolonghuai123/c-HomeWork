#include<iostream>
#include<string>
#include <limits>
#define MAX 1000

using namespace std;

class user {
	public:
		string m_Name;
		int age = 0;
		string gender;
		string address;
		string p_number;
};
struct addressbooks {
	user users[MAX];
	int m_Size =0;
};
int showmenu() {
	cout << "1. 添加联系人" << endl;
	cout << "2. 删除联系人" << endl;
	cout << "3. 显示联系人" << endl;
	cout << "4. 修改联系人" << endl;
	cout << "5. 查找联系人" << endl;
	cout << "6. 清空通讯录" << endl;
	cout << "0. 退出通讯录" << endl;
	return 0;
};


int addusr(addressbooks* abs) {
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加" << endl;
		return 0;
	}
	else
	{
		string name;
		cout << "请输入姓名：" << endl;
		getline(cin,name);
		abs->users[abs->m_Size].m_Name = name;
		int age;
		string input;
		while (true)
		{
			cout << "请输入年龄：" << endl;
			getline(cin,input);
			

			try{
				age = stoi(input);
				if(age>0 && age<150){
					abs->users[abs->m_Size].age = age;
					break;
				}else{
					cout << "非法输入，年龄应在 1~149 之间，请重新输入。" << endl;
					cin.clear();
				};
			}catch(...){
				cout << "非法输入，请输入数字" << endl;
				
			};
		}
		string gender;
		cout << "请输入性别：(男或女)" << endl;
		while(true){
			getline(cin,gender);
			if(gender =="boy"|| gender=="girl" ){
				abs->users[abs->m_Size].gender = gender;
				break;
			}else{
				cout << "非法输入，请重新输入性别" << endl;
			};
		}
		
		string address;
		cout << "请输入联系人地址：" << endl;
		getline(cin,address);
		abs->users[abs->m_Size].address = address;
		string p_number;
		cout << "请输入联系电话：(仅支持中国大陆11位电话号码)" << endl;
		
		while (true)
		{
			getline(cin,p_number);
			if(p_number.length() ==11){
				abs->users[abs->m_Size].p_number = p_number;
				break;
			}else{
				cout << "非法输入，请重新输入联系电话" << endl;
			};
		}
		
		

		cout << "添加联系人成功" << endl;
		abs->m_Size++;
	};
	return 0;
};



void showbase(addressbooks* abs) {
	if (abs->m_Size == 0)
	{
		cout << "通讯录为空" << endl;
	}
	else {
		for (int n = 0; n < abs->m_Size; n++) {
			cout<< "联系人编号: " << (n + 1) << "\t"
				<< "姓名：" << abs->users[n].m_Name << "\t"
				<< "年龄：" << abs->users[n].age << "\t"
				<< "性别：" << abs->users[n].gender << "\t"
				<< "地址：" << abs->users[n].address << "\t"
				<< "联系电话：" << abs->users[n].p_number << endl;
		};
	cout << "*****************************************************************************************************************" << endl;
	};
	

};




int delusr(addressbooks* abs) {
	showbase(abs);
	cout << "请输入要删除的联系人编号：" << endl;
	int n;	
	cin >> n;
	if(n<1 || n>abs->m_Size){
		cout << "输入有误，请重新输入" << endl;

	}else{
		int x;
		while(true){
			cout << "确认删除联系人吗？1. 确认 2. 取消" << endl;
			cin >> x;
			if (x == 1){
				for (int i = n - 1; i < abs->m_Size - 1; i++) {
					abs->users[i] = abs->users[i + 1];
				}
				abs->m_Size--;
				cout << "删除联系人成功，删除数据入下" << endl;
				showbase(abs);
				break;
			}
			else if (x == 2){
				cout << "已取消删除联系人" << endl;
				break;
			}
			else{
				cout << "输入有误，请重新输入" << endl;
			};
		};
	};		
	return 0;
};



int reSetUsr(addressbooks* abs) {
	
	showbase(abs);
	int n;
	cout << "请输入要修改的联系人编号：" << endl;
	cin >> n;
	
	if(n<1 || n>abs->m_Size){
		cout << "输入有误，请重新输入" << endl;
	}else{
		int x;
		while(true){
			cout << "确认修改"<< n <<"号联系人吗？1. 确认 2. 取消" << endl;
			cin >> x;
			if (x == 1){
				string name;
				cout << "请输入姓名：" << endl;
				cin >> name;
				abs->users[n-1].m_Name = name;
				int age;
				cout << "请输入年龄：" << endl;
				cin >> age;
				abs->users[n-1].age = age;
				string gender;
				cout << "请输入性别：" << endl;
				cin >> gender;
				abs->users[n-1].gender = gender;
				string address;
				cout << "请输入联系人地址：" << endl;
				cin >> address;
				abs->users[n-1].address = address;
				string p_number;
				cout << "请输入联系电话：" << endl;
				cin >> p_number;
				abs->users[n-1].p_number = p_number;
				cout << "*****************************************************************************************************************" << endl;
				cout << "修改联系人成功,修改后数据如下" << endl;
				showbase(abs);
				break;
			}
			else if (x == 2){
				cout << "已取消删除联系人" << endl;
				break;
			}
			else{
				cout << "输入有误，请重新输入" << endl;
			};
		};
	};			
	return 0;
};



int findUser(addressbooks* abs) {

	if(abs->m_Size == 0){
		cout << "通讯录为空，无法查找联系人" << endl;
		return 0;

	}

	string finds;
	cout << "请输入要查找的联系人信息：（姓名,电话或者地址都可以）" << endl;
	cin >> finds;
	for(int i =0; i<abs->m_Size; i++){
		if (abs->users[i].m_Name == finds || abs->users[i].p_number == finds || abs->users[i].address == finds){
			cout << "找到联系人如下：" << endl;
			cout << "联系人编号: " << (i + 1) << "\t"
				<< "姓名：" << abs->users[i].m_Name << "\t"
				<< "年龄：" << abs->users[i].age << "\t"
				<< "性别：" << abs->users[i].gender << "\t"
				<< "地址：" << abs->users[i].address << "\t"
				<< "联系电话：" << abs->users[i].p_number << endl;
			cout << "*****************************************************************************************************************" << endl;
		}else{
			cout << "未找到相关联系人" << endl;
		}	
	}
	return 0;
}



int Bye(addressbooks* abs) {
	string x;
	cout << "你确定要清空通讯录吗？此操作无法撤销（输入：YES确定）" << endl;
	cin >> x;

	if( x == "YES"){

		for (int i = 0; i < abs->m_Size; ++i) {
            abs->users[i].m_Name.clear();
            abs->users[i].age = 0;
            abs->users[i].gender.clear();
            abs->users[i].address.clear();
            abs->users[i].p_number.clear();
        }
		abs->m_Size = 0;
		string row = "";
		string maxrow = "=========";
		cout << endl;
		cout << "正在清空通讯录" << endl;
		for (int i = 0; i < 10; ++i) {
			row.push_back('*');
			cout << "{" << row << maxrow << "}" << "  已完成 " << (i + 1) * 10 << "%" << endl;
			if (!maxrow.empty()) {
				maxrow.pop_back(); 
			}
		}
		cout << endl;
		cout << "通讯录已清空" << endl;
		
	}
	return 0;

};



int main() {
	
	system("chcp 65001");

	addressbooks abs;
	abs.m_Size = 0;



	int select = 0;


	while (true)
	{

		showmenu();
		cin >> select;
		switch (select)
		{
		case 1:
			/*cout << "添加联系人" << endl;*/
			addusr(&abs);
			break;
		case 2:
			/*cout << "删除联系人" << endl;*/
			delusr(&abs);
			break;
		case 3:
			/*cout << "显示联系人" << endl;*/
			showbase(&abs);
			break;
		case 4:
			/*cout << "修改联系人" << endl;*/
			reSetUsr(&abs);
			break;
		case 5:
			/*cout << "查找联系人" << endl;*/
			findUser(&abs);
			break;
		case 6:
			/*cout << "清空联系人" << endl;*/
			Bye(&abs);
			break;
		case 0:
			/*cout << "退出通讯录" << endl;*/
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}

	};








};
