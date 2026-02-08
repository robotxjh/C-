// 封装显示界面的函数  void showmenu()
// 在main() 函数中调用该函数
#include<iostream>
#include<string>
#define MAX 1000
using namespace std;

// 设计联系人结构体
struct Person
{
	string m_Name;
	int m_Sex = 0; // 1、男  2、女
	int m_Age = 0;
	string m_Phone;
	string m_Addr;
};
// 设计通讯录结构体
struct Addressbooks
{
	//通讯录中保存的联系人数组
	struct Person personArray[MAX];
	//通讯录中当前记录的联系人个数
	int m_size = 0;
};

// 添加联系人
void addPerson(Addressbooks* abs)
{
	// 判断通讯录是否已满，如果已经满，就不在添加
	if (abs->m_size > MAX)
	{
		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	else
	{
		//添加具体的联系人
		//添加姓名
		if (abs->m_size < MAX)
		{
			string name;
			cout << "请输入姓名" << endl;
			cin >> name;
			abs->personArray[abs->m_size].m_Name = name;
		}
		else
		{
			cout << "通讯录已满，不能添加" << endl;
		}
		// 添加性别
		cout << "请输入性别" << endl;
		cout << "1 ————男  2————女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_size].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		//添加年龄
		int age = 0;
		while (true)
		{
			cout << "请输入年龄（0-119）" << endl;
			cin >> age;
			if (age > 0 && age < 120)
			{
				abs->personArray[abs->m_size].m_Age = age;
				break;
			}
			cout << "年龄不符合常理，请重新输入" << endl;
		}
		// 添加电话
		string phone;
		cout << "请输入电话" << endl;
		cin >> phone;
		abs->personArray[abs->m_size].m_Phone = phone;
		//添加地址
		string address;
		cout << "请输入家庭住址" << endl;
		cin >> address;
		abs->personArray[abs->m_size].m_Addr = address;

		//更新通讯录人数
		abs->m_size++;

		cout << "添加成功" << endl;

		system("pause");
		system("cls");

	}
}

//2、显示所有联系人
void showPersion(Addressbooks * abs)
{
	//判断通讯录中人数是否为零
	if (abs->m_size == 0)
	{
		cout << "当前通讯录为空" << endl;
	}
	else
	{	
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << " 姓名: " << abs->personArray[i].m_Name ;
			cout << " 性别: " << abs->personArray[i].m_Sex ;
			cout << " 年龄: " << abs->personArray[i].m_Age ;
			cout << " 电话: " << abs->personArray[i].m_Phone ;
			cout << " 住址: " << abs->personArray[i].m_Addr << endl;
			
		}
	}
	system("pause");
	system("cls");
}

// 检测联系人是否存在，若存在，返回联系人信息
//参数1 通讯录  参数2 查找的人名
int isExist(Addressbooks * abs, string name)
{
	for (int i = 0; i < abs->m_size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i; //找到了的话，返回这个人的通讯录编号
		}
	}
	//没找到的话，返回-1
	return -1;
}
//删除指定联系人
void deletePerson(Addressbooks* abs)
{
	cout << "请输入要查找的联系人i姓名：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs,name);
	if(ret == -1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		cout << "找到联系人" << endl;
		cout << " 1  -删除，2  -不删除" << endl;
		int select;
		cin >> select;
		switch (select)
		{
			case 1:
				for (int i = ret; i < abs->m_size; i++)
				{
					//数据前移
					abs->personArray[i] = abs->personArray[i + 1];
				}
				abs->m_size--; // 更新通讯录中的人数
				cout << "删除成功" << endl;
				break;
			case 2:
				cout << "取消删除" << endl;
				break;

		}
	}
}
// 查找联系人
void findPerson(Addressbooks * abs)
{
	cout << "请输入要查找的联系人" << endl;
	string name;
	cin >> name;
	for (int i = 0; i < abs->m_size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			cout << "姓名：" << abs->personArray[i].m_Name << "\t" ;
			cout << "性别：" << abs->personArray[i].m_Sex << "\t" ;
			cout << "年龄：" << abs->personArray[i].m_Age << "\t" ;
			cout << "电话：" << abs->personArray[i].m_Phone << "\t" ;
			cout << "地址：" << abs->personArray[i].m_Addr << "\t" << endl;
		}
		else
		{
			cout << "未找到此人" << endl;
		}

	}
	system("pause");
	system("cls");
	 
}

// 修改联系人
void modifyPerson(Addressbooks* abs)
{
	cout << "请输入要修改的联系人姓名：" << endl;
	string name;
	cin >> name;
	for (int i = 0; i < abs->m_size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			cout << "查到要修改的的联系人" << endl;
			cout << "请输入新的名字：" << endl;
			string name;
			cin >> name;
			abs->personArray[i].m_Name = name; 
			abs->personArray[i].m_Name = name;
			cout << "请输入新的性别：1 --男，2 --女" << endl;
			int sex = 0;
			while (true)
			{
				cin >> sex;
				if (sex == 1 || sex == 2)
				{
					abs->personArray[abs->m_size].m_Sex = sex;
					break;
				}
				cout << "输入有误，请重新输入" << endl;
			}
			cout << "请输入新的年龄：" << endl;
			int age;
			cin >> age;
			abs->personArray[i].m_Age = age; 
			cout << "请输入新的电话：" << endl;
			string phone;
			cin >> phone;
			abs->personArray[i].m_Phone = phone;
			cout << "请输入新的住址：" << endl;
			string addr;
			cin >> addr;
			abs->personArray[i].m_Addr = addr;
			
		}
		else
		{
			cout << "未找到要修改的联系人" << endl;
		}

	}
	cout << "修改完成" << endl;

}
// 清空联系人
void cleanPerson(Addressbooks* abs)
{
	cout << "确定要清空联系人吗？ 1 --清空， 2 --不清空" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		abs->m_size = 0;
		cout << "通讯录为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "取消清空联系人" << endl;
	}
}

//菜单界面
void showMeau()
{
	cout << "*****************************" << endl;
	cout << "***** 1. add    contact *****" << endl;
	cout << "***** 2. show   contact *****" << endl;
	cout << "***** 3. remove contact *****" << endl;
	cout << "***** 4. find   contact *****" << endl;
	cout << "***** 5. reset  contact *****" << endl;
	cout << "***** 6. clean  contact *****" << endl;
	cout << "***** 7. exit   contact *****" << endl;
	cout << "*****************************" << endl;
}
int main()
{
	// 创建通讯录结构体变量
	Addressbooks abs;
	//初始化通讯录中当前的人员个数
	abs.m_size = 0;


	int select = 0; // 用户选择输入的变量
	while (true)
	{
		// 调用显示函数
		showMeau();
		cin >> select;
		switch (select)
		{
		case 1: // 添加联系人
			addPerson(&abs); //利用地址传递可以修饰实参
			break;

		case 2: // 显示联系人
			showPersion(&abs);
			break;

		case 3: // 删除联系人		
			deletePerson(&abs);
			break;
	
		case 4: // 查找联系人
			findPerson(&abs);
			break;

		case 5: // 修改联系人
			modifyPerson(&abs);
			break;

		case 6: // 清空联系人
			cleanPerson(&abs);
			break;

		case 0: // 退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;

		default: // 退出通讯录
			break;
		}
	}

}