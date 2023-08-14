#include <iostream> // input output stream i think?
#include <string>

#include <fstream> // guess that stands for file-stream? idk?
// What program should we make?
// maybe something like a password manager?? 
// lets make that
void login();
void _register();
void main_menu();
void _quit();
void delete_user();
void _menu();

// adding the definitions for this functions, so nothing is undefined :)


using namespace std;
string g_usr;
string g_pwd;
void main_menu()
{
	string option; // we need to make it a string, because the user can type maybe something else then a number
	while (true)
	{
		// lets first add an option to our first question: To quit the program natural...
		// lets add another option to our first question to delete a user, so we have our login/register program. 
		cout << "Welcome to my password manager... How can i help you, please select one of the options: " << endl << "[1] Login with user" << endl << "[2] Create new user" << endl << "[3] Delete user" << endl << "[4] Go out the password manager" << endl;
		// need to make sure that the endline is there
		getline(cin >> ws, option);
		// guess we'll have to add if/else statements
		// we got two likes... Thanks!
		if (option == "1")
		{
			login();
			break;
		}
		else if (option == "2")
		{
			_register();
			break;
		}
		else if (option == "3")
		{
			delete_user();
			break;
		}
		else if (option == "4")
		{
			_quit();
			break;
		}
		else
		{
			cout << "Not a valid option... Please choose from 1 to 2!" << endl;
			continue;
		} // lets just make a hole INSECURE pwd manager and lets then later upgrade it to SECURE...
	}
}
void login()
{
	string current_read_txt;
	string r_name;
	string r_pwd;
	string readed_file;
	bool reading_password = false;
	string l_name;
	string l_pwd;

	cout << "[?] What is your username?" << endl;
	getline(cin >> ws, l_name);

	cout << "[?] What is your password?" << endl;
	getline(cin >> ws, l_pwd);
	// seems good...

	ifstream account_file("users.pmd"); // input file stream i think?

	while (getline(account_file, current_read_txt))
	{
		readed_file = current_read_txt;
	};

	for (char& c : readed_file)
	{
		if (c != ',' && !reading_password)
			r_name += c;
		else if (c == ',' && !reading_password)
		{
			reading_password = true; // very dirty way but yeah... hehe 
			continue; // makes sure it doesnt add the comma to the password variable
		}

		if (reading_password) // bruh :(
			r_pwd += c;
	}

	if (l_name == r_name && l_pwd == r_pwd)
	{
		std::cout << "Username is correct and password is correct. You are in!" << endl;
		g_usr = l_name;
		g_pwd = l_pwd;

		// it gets end here, we need to return back to the main menu (for now)
		_menu();
	}
	else
	{
		std::cout << "Incorrect username and/or password... Returning to main menu..." << endl;
		main_menu();
	}
	account_file.close();
}
// need to add underscore because register is used by the C++ language... 
void _register()
{
	// what where doing is creating a file named users.password-manager-database
	// that name i just got up, but you can use any filename... Lets write a test!

	string name;
	string pwd;
	// switching these up so it feels more natural 
	cout << "[?] What will be your new username?" << endl;
	getline(cin >> ws, name); // I CANT READ XD

	cout << "[?] What will be your new password?" << endl;
	getline(cin >> ws, pwd); // LOL XD 
	// boom, we got it

	// importing it into the file...

	ofstream account_file("users.pmd"); // output file stream i think?
	string file_content = name + "," + pwd;
	account_file << file_content;
	account_file.close();
	// whoo i typed a long commend, better made it in /**/ this block comment
	// NOW I KNOW! So when we created the file, we didnt immidiatly closed the file, so it will be closed on the end, but since we dit a Ctrl+C end, and it throws error, it doenst end the normal way, so it will be breaked and the file couldnt be written to... But since we had a natural ending on the 2nd try, we got the file closed and we could write to the file...  Now, we close the file, so we DONT need an ending. See?
	// thats better, i dont know what the bug was.. maybe because we quit with Ctrl+C??? idk man alr everything seems good to now.
	// gonna seperate it by commas...

	cout << "[+] Succesfully created new user! Returning back to main menu... " << endl;
	main_menu();
	// now it will be fixed, so we can call the main menu in a method, while NOT calling the 'main' method

}
void delete_user()
{
	string current_read_txt;
	string r_name;
	string r_pwd;
	string readed_file;
	bool reading_password = false;
	string l_name;
	string l_pwd;

	cout << "[?] What is your username?" << endl;
	getline(cin >> ws, l_name);

	cout << "[?] What is your password from that username?" << endl;
	getline(cin >> ws, l_pwd);
	// seems good...

	ifstream account_file("users.pmd"); // input file stream i think?

	while (getline(account_file, current_read_txt))
	{
		readed_file = current_read_txt;
	};

	for (char& c : readed_file)
	{
		if (c != ',' && !reading_password)
			r_name += c;
		else if (c == ',' && !reading_password)
		{
			reading_password = true; // very dirty way but yeah... hehe 
			continue; // makes sure it doesnt add the comma to the password variable
		}

		if (reading_password) // bruh :(
			r_pwd += c;
	}
	// yoink Xd
	// BBRO HAHA I CANT READ WHATS HAHA
	if (l_name == r_name && l_pwd == r_pwd) // WHOOPS....
	{
		// we then delete the user  and password, so we create a new file user.pmd, which overrides it
		ofstream account_file("users.pmd");
		account_file.close();
		cout << "[!] Succesfully deleted user " << l_name << " from the file!" << endl;
		main_menu();
		// returning to main menu
	}
	// alr, hope someone sees the stream til now

	else
	{
		cout << "[!] Could not delete user because the password and/or user is incorrect" << endl;
		// Hmmm seems weird
		main_menu();
	}
	// alr, seems good!
}
void _quit()
{
	exit(0);
}
void _menu()
{
	// we can now access the variables
	// lets first cout a welcome message
	while (true)
	{
		string help_option;
		cout << "Welcome, " << g_usr << ". How can we help you?" << endl;
		getline(cin >> ws, help_option);
		cout << "Okay, helping you with: " << help_option << endl;
		// thats because another instance is running for our program
		// if we terminate the already running instance, you'll see we get no errors
		// alr, see? now its working...
		// alright, lets see how the stream is  going
		// Alright! Thank you so much for watching! I have to go, but no worries, i'll make a part 3 when i can!
		// got streaming for 46 minutes. Thats nice!
		// bye everyone, i will have a github repository where you can download the project. Thanks and see you later!
	}
}
int main()
{
	main_menu();
	return 0;
}
// alright, good work, we got 206 lines of code!
// now lets make a function for when we got into the account. lets first store the username and password in a global variable.
