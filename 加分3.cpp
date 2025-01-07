#include <bits/stdc++.h>
#include <windows.h>

using namespace std;
//初始題目 
int board[9][9] = {
    {5,3,0,0,7,0,0,0,0},
    {6,0,0,1,9,5,0,0,0},
    {0,9,8,0,0,0,0,6,0},
    {8,0,0,0,6,0,0,0,3},
    {4,0,0,8,0,3,0,0,1},
    {7,0,0,0,2,0,0,0,6},
    {0,6,0,0,0,0,2,8,0},
    {0,0,0,4,1,9,0,0,5},
    {0,0,0,0,8,0,0,7,9},
    
};

bool editable[9][9];

int cur_r = 0, cur_c = 0;



int check_horizontal(int i,int j)
{
    /* TODO: Check if a horizontal line has conflict number, or is finished. */
    int k=0,t=0,r=0;
    for(int n=0;n<9;n++){
    	for(int m=0;m<9;m++){
    		if(board[i][n]==board[i][m]&&board[i][n]!=0){
    			k++;
			}
			else if(board[i][n]!=board[i][m]&&board[i][n]!=0){
				r++;
			}
		}
	}
	for(int m=0;m<9;m++){
    		if(board[i][m]!=0){
    			t++;
			}
			}
	if(k>t){
		return 1;
	}
	else if(r==72){
		return 2;
	}
    return 0;
}

int check_vertical(int i,int j)
{
    /* TODO: Check if a vertical line has conflict number, or is finished. */
    int k=0,t=0,r=0;
    for(int n=0;n<9;n++){
    	for(int m=0;m<9;m++){
    		if(board[n][j]==board[m][j]&&board[n][j]!=0){
    			k++;
			}
			else if(board[n][j]!=board[m][j]&&board[n][j]!=0){
				r++;
			}
		}
	}
	for(int m=0;m<9;m++){
    		if(board[m][j]!=0){
    			t++;
			}
			}
	if(k>t){
		return 1;
	}
	else if(r==72){
		return 2;
	}
	
    return 0;
}

int check_block(int i,int j)
{
    /* TODO: Check if a block has conflict number, or is finished. */
    int k=0,t=0;//k紀錄重複幾次 t紀錄幾個非0數字
    //判斷當前格子是在九宮格哪一格 
	if(i/3==0&&j/3==0){
		//每一格都跟每一格比較一次 
		for(int n=0;n<=2;n++){
			for(int m=0;m<=2;m++){
				//有數字t++ 
				if(board[n][m]!=0) t++;
				for(int x=0;x<=2;x++){
					for(int y=0;y<=2;y++){
						//如果自己跟對方相同k++ 
						if(board[n][m]==board[x][y]&&board[n][m]!=0) k++;
					}
				}
			}
		}
	}
	else if(i/3==1&&j/3==0){
		for(int n=3;n<=5;n++){
			for(int m=0;m<=2;m++){
				if(board[n][m]!=0) t++;
				for(int x=3;x<=5;x++){
					for(int y=0;y<=2;y++){
						if(board[n][m]==board[x][y]&&board[n][m]!=0) k++;
					}
				}
			}
		}
	}
	else if(i/3==2&&j/3==0){
		for(int n=6;n<=8;n++){
			for(int m=0;m<=2;m++){
				if(board[n][m]!=0) t++;
				for(int x=6;x<=8;x++){
					for(int y=0;y<=2;y++){
						if(board[n][m]==board[x][y]&&board[n][m]!=0) k++;
					}
				}
			}
		}
	}
	else if(i/3==0&&j/3==1){
		for(int n=0;n<=2;n++){
			for(int m=3;m<=5;m++){
				if(board[n][m]!=0) t++;
				for(int x=0;x<=2;x++){
					for(int y=3;y<=5;y++){
						if(board[n][m]==board[x][y]&&board[n][m]!=0) k++;
					}
				}
			}
		}
	}
	else if(i/3==1&&j/3==1){
		for(int n=3;n<=5;n++){
			for(int m=3;m<=5;m++){
				if(board[n][m]!=0) t++;
				for(int x=3;x<=5;x++){
					for(int y=3;y<=5;y++){
						if(board[n][m]==board[x][y]&&board[n][m]!=0) k++;
					}
				}
			}
		}
	}
	else if(i/3==2&&j/3==1){
		for(int n=6;n<=8;n++){
			for(int m=3;m<=5;m++){
				if(board[n][m]!=0) t++;
				for(int x=6;x<=8;x++){
					for(int y=3;y<=5;y++){
						if(board[n][m]==board[x][y]&&board[n][m]!=0) k++;
					}
				}
			}
		}
	}
	else if(i/3==0&&j/3==2){
		for(int n=0;n<=2;n++){
			for(int m=6;m<=8;m++){
				if(board[n][m]!=0) t++;
				for(int x=0;x<=2;x++){
					for(int y=6;y<=8;y++){
						if(board[n][m]==board[x][y]&&board[n][m]!=0) k++;
					}
				}
			}
		}
	}
	else if(i/3==1&&j/3==2){
		for(int n=3;n<=5;n++){
			for(int m=6;m<=8;m++){
				if(board[n][m]!=0) t++;
				for(int x=3;x<=5;x++){
					for(int y=6;y<=8;y++){
						if(board[n][m]==board[x][y]&&board[n][m]!=0) k++;
					}
				}
			}
		}
	}
	else if(i/3==2&&j/3==2){
		for(int n=6;n<=8;n++){
			for(int m=6;m<=8;m++){
				if(board[n][m]!=0) t++;
				for(int x=6;x<=8;x++){
					for(int y=6;y<=8;y++){
						if(board[n][m]==board[x][y]&&board[n][m]!=0) k++;
					}
				}
			}
		}
	}
	if(k>t){
		//重複的數字大於有數字的格子代表有重複的兩個數字 
		return 1;
	}
	if (k==9){
		//重複的數字等於9就代表每個數字都只跟自己重複一次 
		return 2;
	}
	return 0;
}


void fill_number(char c)
{
    /* TODO: Fill a number in to the cell the cursor is now pointing to.
             After fill in the number, check the horizontal line, the
             vertical line and the block the cell is in.
     */
     if (c=='1'){
     		board[cur_r][cur_c]=1;
     		return;
		 }
		 
		else if (c=='2'){
     		board[cur_r][cur_c]=2;
     		return;
		 }
     	
     	else if (c=='3'){
     		board[cur_r][cur_c]=3;
     		return;
		 }
		
		else if (c=='4'){
			board[cur_r][cur_c]=4;
			return;
		}
		else if (c=='5'){
			board[cur_r][cur_c]=5;
			return;
		}
		else if (c=='6'){
			board[cur_r][cur_c]=6;
			return;
		}
		else if (c=='7'){
			board[cur_r][cur_c]=7;
			return;
		}
		else if (c=='8'){
			board[cur_r][cur_c]=8;
			return;
		}
		else if (c=='9'){
			board[cur_r][cur_c]=9;
			return;
		}
		else if (c=='0'){
			board[cur_r][cur_c]=0;
			return;
		}

}

void move_cursor(char c)
{
    /* TODO: Move the cursor up, down, to the left or to the right.
             Remember to check if the cursor is moving out of bound.
    */
    if(c=='w'||c=='W'){
		if(cur_r-1>=0){
			if(editable[cur_r-1][cur_c]==0&&editable[cur_r-2][cur_c]==0&&editable[cur_r-3][cur_c]==0){
				if(cur_r-4>=0)cur_r-=4;
			}
			else if(editable[cur_r-1][cur_c]==0&&editable[cur_r-2][cur_c]==0){
				if(cur_r-3>=0)cur_r-=3;
			}
			else if(editable[cur_r-1][cur_c]==0){
				if(cur_r-2>=0)cur_r-=2;
			}
			else{
				cur_r--;
			}
		}
	}
	else if(c=='s'||c=='S'){
    	if(cur_r+1<9){
			if(editable[cur_r+1][cur_c]==0&&editable[cur_r+2][cur_c]==0&&editable[cur_r+3][cur_c]==0){
				if(cur_r+4<9)cur_r+=4;
			}
			else if(editable[cur_r+1][cur_c]==0&&editable[cur_r+2][cur_c]==0){
				if(cur_r+3<9)cur_r+=3;
			}
			else if(editable[cur_r+1][cur_c]==0){
				if(cur_r+2<9)cur_r+=2;
			}
			else{
				cur_r++;
			}
		}
	}
	else if(c=='d'||c=='D'){
    	if(cur_c+1<9){
    		if(editable[cur_r][cur_c+1]==0&&editable[cur_r][cur_c+2]==0&&editable[cur_r][cur_c+3]==0){
				if(cur_c+4<9)cur_c+=4;
			}
			else if(editable[cur_r][cur_c+1]==0&&editable[cur_r][cur_c+2]==0){
				if(cur_c+3<9)cur_c+=3;
			}
			else if(editable[cur_r][cur_c+1]==0){
				if(cur_c+2<9)cur_c+=2;
			} 
			else{
				cur_c++;
			}
		}
	}
	else if(c=='a'||c=='A'){
    	if(cur_c-1>=0){
    		if(editable[cur_r][cur_c-1]==0&&editable[cur_r][cur_c-2]==0&&editable[cur_r][cur_c-3]==0){
				if(cur_c-4>=0)cur_c-=4;
			}
			else if(editable[cur_r][cur_c-1]==0&&editable[cur_r][cur_c-2]==0){
				if(cur_c-3>=0)cur_c-=3;
			}
			else if(editable[cur_r][cur_c-1]==0){
				if(cur_c-2>=0)cur_c-=2;
			}
			else{
				cur_c--;
			}
		}
	}

}

bool is_invalid(int i, int j)
{
    /* TODO: Check if board[i][j] is in a line that has conflict numbers. */
    check_horizontal(i,j);
    check_block(i,j);
    check_vertical(i,j);
    if(check_horizontal(i,j)==1){
    	return true;
	}
	else if(check_block(i,j)==1){
    	return true;
	}
	else if(check_vertical(i,j)==1){
    	return true;
	}
    return false;
}

bool is_done(int i, int j)
{
    /* TODO: Check if board[i][j] is in a line that has finished. */
    check_horizontal(i,j);
    check_block(i,j);
    check_vertical(i,j);
    if(check_horizontal(i,j)==2){
    	return true;
	}
	else if(check_block(i,j)==2){
    	return true;
	}
	else if(check_vertical(i,j)==2){
    	return true;
	}
    return false;
}

bool check_win()
{
    /* TODO: Check if the game is set. That is, every cell is finished. */
    /* TODO: Check if the game is set. That is, every cell is finished. */
    int k=0;
    for(int i=0;i<9;i++){
    	for(int j=0;j<9;j++){
    		if(check_horizontal(i,j)==2)k++;
    		if(check_vertical(i,j)==2)k++;
    		if(check_block(i,j)==2)k++;
		}
	}
    if(k==243)return true;
    return false;

	return false;
}

bool ans(int board[9][9]){
	
			for(int j=0;j<9;j++){
				for(int i=0;i<9;i++){
					//判斷那格是否為空的格子 
					if(board[i][j]==0){
						//新增一個陣列 
						int a[9]={1,2,3,4,5,6,7,8,9};
						//打亂陣列 
						random_device rd;
						mt19937 g(rd());
						shuffle(begin(a), end(a), g);
						
						for(int u=0;u<9;u++){
							//該格隨機等於陣列的某個數字 
							board[i][j]=a[u];
							//判斷現在填的數字是否重複以及再一次執行該函式判斷下一個數字是否1-9都不成立 
							if (!is_invalid(i, j) && ans(board)) {
							 return true; 
							 }
							 //若上述判斷為false則當前格子設為0繼續進入for迴圈 
							 board[i][j] = 0; 
						}
						//若1-9皆為false則return false讓上一個格子繼續for 迴圈 
						return false;
					}
				}
			}
			//若每個格子都填滿則結束 
			return true;
		}
void question(){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			//將所有格子初始化 
			board[i][j]=0;
		}
	}
	//隨機生成一種答案 
	ans(board);
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			//若board[i][j]是一開始題目有出現數字的格子就continue 
			if(editable[i][j]==0) continue;
			//否則該格子顯示0 
			else board[i][j]=0;
		}
	}
}
bool is_moving_action(char c)
{
    return (c == 'W' || c == 'w' || c == 'S' || c == 's' ||
            c == 'A' || c == 'a' || c == 'D' || c == 'd');
}

bool is_filling_action(char c)
{
    return (c >= '0' && c <= '9');
}

string get_styled_text(string text, string style)
{
    string color = "", font = "";
    for (char c : style)
    {
        if (c == 'R')
            color = "31";
        if (c == 'G')
            color = "32";
        if (c == 'E')
            color = "41";
        if (c == 'C')
            color = "106";
        if (c == 'B')
            font = ";1";
    }
    return "\x1b[" + color + font + "m" + text + "\x1b[0m";
}

void print_board()
{
    // Flush the screen
    cout << "\x1b[2J\x1b[1;1H";

    // Print usage hint.
    cout << get_styled_text("W/A/S/D: ", "B") << "move cursor" << endl;
    cout << get_styled_text("    1-9: ", "B") << "fill in number" << endl;
    cout << get_styled_text("      0: ", "B") << "clear the cell" << endl;
    cout << get_styled_text("      Q: ", "B") << "quit" << endl;
    cout << get_styled_text("      O: ", "B") << "ANSWER" << endl;
    cout << endl;

    // Iterate through and print each cell.
    for (int i = 0; i < 9; ++i)
    {
        // Print horizontal divider.
        if (i && i % 3 == 0)
            cout << "-------------------------------" << endl;

        // Print the first vertical divider in each line.
        cout << "|";
        for (int j = 0; j < 9; ++j)
        {
            // Set text style based on the state of the cell.
            string style = "";

            // Set style for the cell the cursor pointing to.
            if (cur_r == i && cur_c == j)
                style = "C";
            // Set style for the cell in an invalid line.
            else if (is_invalid(i, j))
                style = "E";
            // Set style for the cell in a finished line.
            else if (is_done(i, j))
                style = "G";

            // Set style for a the cell that is immutable.
            if (!editable[i][j])
                style += "B";

            // Print the cell out in styled text.
            // If the content is 0, print a dot, else print the number.
            if (board[i][j] == 0)
                cout << get_styled_text(" · ", style);
            else
                cout << get_styled_text(" " + to_string(board[i][j]) + " ", style);

            // Print the vertical divider for each block.
            if ((j + 1) % 3 == 0)
                cout << "|";
        }
        cout << endl;
    }
}

void initialize()
{
    // Set up styled text for Windows.
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);

    // Mark editable cells
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
            editable[i][j] = !board[i][j];
            
    
    // 第一遍判斷初始題目該格是否有數字不輸出board，重新設定完題目再輸出 
	
}

int main()
{
    char c;
    bool action_ok;
    
	//判斷初始題目 
    initialize();
    //重新設定題目 
	question();
	//輸出 
    print_board();
    while (cin >> c)
    {
        action_ok = false;
        if (is_moving_action(c))
        {
            action_ok = true;
            move_cursor(c);
        }

        if (is_filling_action(c))
        {
            action_ok = true;
            fill_number(c);
        }

        if (c == 'Q' || c == 'q')
            break;
		if(c=='O'){
			//若為O則輸出答案 
			action_ok = true;
			ans(board);
		}
        print_board();
		
        if (check_win()&&c!='O')//若輸入O則代表是查看答案因此不算win 
        {
            cout << "YOU WIN!" << endl;
            break;
        }

        if (!action_ok)
            cout << get_styled_text("!!! Invalid action !!!", "R");
    }


}


