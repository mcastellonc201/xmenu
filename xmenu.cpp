#define NOPTIONS 7
#include <iostream>
#include <windows.h>
#include <xinput.h>
#pragma comment(lib,"xinput.lib")


int main()
{
	XINPUT_KEYSTROKE stroke;

	system("mode con: cols=100 lines=40");
	SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);

	std::string Menu[NOPTIONS] = {
		"  GAME01.CMD  ",
		"  GAME02.CMD  ",
		"  GAME03.CMD  ",
		"  GAME04.CMD  ",
		"  GAME05.CMD  ",
		"  REBOOT      ",
		"  POWEROFF    "
	};
	int index = 0;

	while (true)
	{
		system("cls");
		std::cout << "==============\n";
		std::cout << "     MENU     \n";
		std::cout << "==============\n";
		for (int i = 0; i < NOPTIONS; ++i)
		{
			if (i == index)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 128);
				std::cout << Menu[i] << std::endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			else
			{
				std::cout << Menu[i] << std::endl;
			}
		}
		std::cout << "==============\n";

		while (true)
		{
			DWORD Result = XInputGetKeystroke(0, 0, &stroke);
			if ((stroke.VirtualKey == VK_PAD_DPAD_UP) && (stroke.Flags & XINPUT_KEYSTROKE_KEYDOWN))
			{
				index -= 1;
				if (index == -1)
				{
					index = NOPTIONS-1;
				}
				break;
			}
			else if ((stroke.VirtualKey == VK_PAD_DPAD_DOWN) && (stroke.Flags & XINPUT_KEYSTROKE_KEYDOWN))
			{
				index += 1;
				if (index == NOPTIONS)
				{
					index = 0;
				}
				break;
			}
			else if ((stroke.VirtualKey == VK_PAD_A) && (stroke.Flags & XINPUT_KEYSTROKE_KEYDOWN))
			{
				switch (index)
				{
				case 0:
				{
					system("cls");
					system("game01.cmd");
				}
				break;
				case 1:
				{
					system("cls");
					system("game02.cmd");
				}
				break;
				case 2:
				{
					system("cls");
					system("game03.cmd");
				}
				break;
				case 3:
				{
					system("cls");
					system("game04.cmd");
				}
				break;
				case 4:
				{
					system("cls");
					system("game05.cmd");
				}
				break;
				case 5:
				{
					system("shutdown -r -t 0");
				}
				break;
				case 6:
				{
					system("shutdown -s -t 0");
				}
				break;

				}
				break;

			}
		}
		Sleep(10);
	}
	return 0;
}
