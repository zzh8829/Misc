求解骑士游历问题 
显然求解骑士游历问题的每一步就是马在棋盘上走的一步。在每一步马需要选择一个方向进行游历，这时记住解的每一步需要记住两件事： 
1.当前步的行列位置 
2.当前步已经试探过哪些方向了，以便回溯回来时能够选择一个新的方向进行试探 
所以使用两个数组，数组board记住棋盘的每个位置是在马的第几步到达的，这反映了问题的解，即第几步到哪个位置。数组direction记住在棋盘的某个位置已经试探过的方向，每个位置有八个方向，可按某种顺序对八个方向编号，然后在每个位置按编号顺序试探方向。 
在确定数据结构之后，同样需要确定下面几个问题： 
1.怎样的状态是初始状态。 
2.怎样选择当前步可能的路线 
3.怎样表示向前推进一步 
4.怎样回溯及清除当前步的痕迹 
显然初始状态是棋盘的每个位置都置为第0步到达（即还没有到达），每个位置都还没有选择任何方向（可赋值MAX_DIR(=8)表示没有选择方向）。 
选择当前步可能的路线就是在当前位置选择一个方向来游历下一步。在选择的时候同样需要区分是从第0个方向开始考虑还是从上一次的下一个方向开始考虑。为了方便从下一个方向开始考虑，实际上数组direction在某一位置(curr_x, curr_y)的值记住的是从上一位置选择了哪个编号的方向而到达的，这样容易回溯到上一位置，而且容易在回溯到上一位置之后从下个一方向重新试探。 
向前推进一步则要根据所选择的方向推进到下一位置，记住到下一位置所选择的方向，下一位置是第几步到达的，然后增加步数。 
回溯一步则要标记当前位置没有到达过（将到达的步数置为0），根据上一步到当前位置的所选择的方向（这个方向是记录当前位置所对应的direction数组中）而回溯到上一位置，然后减少步数。 
下面程序用类KNIGHT来封装数组board、direction、当前位置(curr_x, curr_y)、当前步数(step)，并且使用last_direction来记住上一位置到当前位置所选择的方向。为了方便计算选择一个方向后从当前推进到下一位置，使用数组var_x和var_y来记住每个方向在x方向和y方向的改变值。这个类中提供的方法的含义与类QUEEN类似。为节省篇幅起见，我们将类的界面、实现及演示放在了同一文件。

///////////////////////////////////////////////////////////////////////
程序二：求解骑士游历问题的程序 

// 文件：KNIGHT.CPP 
// 功能：使用回溯算法求解骑士游历问题
#include <iostream.h> 
#include <iomanip.h> 
enum BOOLEAN { 
TRUE = 1, 
FALSE = 0 
}; 
const int MAX_WIDTH = 30; 
const int MAX_DIR = 8; 
class KNIGHT { 
public: 
// FUNCTION: 设置初始状态 
KNIGHT(int width); 
// FUNCTION: 用比较直观的方式打印问题的解 
// REQUIRE: 必须先调用了成员函数tourist() 
void print(); 
// FUCTION: 根据马的起始位置(start_x, start_y)使用回溯算法求骑士游历问题的一个解 
// REQUIRE: (start_x, start_y)必需在所设置的棋盘宽度范围内 
BOOLEAN tourist(int start_x, int start_y); 
protected: 
// FUNCTION: 初始化记录所选方向的数组，将每个值置为MAX_DIR 
void init_direction(); 
// FUNCTION: 初始化记录马在第几步到位每个位置的数组，将每个值置为0 
void init_chessboard(); 
// FUNCTION: 设置初始状态，包括初始化方向数组和棋盘数组，并设置马的初始位置 
void set_start(int x, int y); 
// FUNCTION: 在当前位置选择一个方向以推进到下一位置 
// RETURN: 如果可选择一个方向推进则返回TRUE，否则返回FALSE 
// NOTE: 将该函数定义为虚函数，以便下面快速游历的类来重定义该函数而产生动态绑定 
virtual BOOLEAN select_direction(); 
// FUNCTION: 从当前位置回溯到上一位置 
// NOTE: 将该函数定义为虚函数，以便下面快速游历的类来重定义该函数而产生动态绑定 
virtual void backward(); 
// FUNCTION: 从当前位置推进到下一位置 
// NOTE: 将该函数定义为虚函数，以便下面快速游历的类来重定义该函数而产生动态绑定 
virtual void forward(); 
// FUNCTION: 判断马是否能够走向位置(x, y)。 
// RETURN: 如果马已经到过该位置，或该位置超出棋盘范围返回FALSE，否则返回TRUE 
BOOLEAN is_legal(int x, int y); 
// FUNCTION: 判断是否回溯到初始状态 
// RETURN: 如果步数回到第1步则表示回到初始状态而返回TRUE，否则返回FALSE 
BOOLEAN back_to_start(); 
// FUNCTION: 判断是否游历完所有位置 
// RETURN: 如果步数等于棋盘格子数则表示游历完所有位置而返回TRUE，否则返回FALSE 
BOOLEAN is_end(); 
// 下面两个数组用来记住选择某个方向后，推进到下一位置时x方向和y方向的值的变化 
int var_x[MAX_DIR]; 
int var_y[MAX_DIR]; 
// 记录马第几步到达某个位置的棋盘数组 
int chessboard[MAX_WIDTH][MAX_WIDTH]; 
// 记录马在某个位置是在上一位置选择第几个方向到达的 
int direction[MAX_WIDTH][MAX_WIDTH]; 
int width; // 棋盘宽度 
int curr_x, curr_y; // 马的当前位置 
int step; // 已经游历的步数 
int last_direct
ion; // 上一位置到当前位置所选的方向 
}; 
KNIGHT::KNIGHT(int width) 
{ 
this->width = width; 
init_direction(); 
total_step = 0; 
} 
void KNIGHT::print() 
{ 
int x, y; 
cout << " +"; 
for (x = 0; x < width; x = x + 1) cout << "----+"; 
cout << '\n'; 
for (x = 0; x < width; x = x + 1) { 
cout << " |"; 
for (y = 0; y < width; y = y + 1) cout << setw(3) << chessboard[x][y] << " |"; 
cout << '\n'; 
cout << " +"; 
for (y = 0; y < width; y = y + 1) cout << "----+"; 
cout << '\n'; 
} 
} 
BOOLEAN KNIGHT::is_legal(int x, int y) 
{ 
if (x < 0 || x >= width) return FALSE; 
if (y < 0 || y >= width) return FALSE; 
if (chessboard[x][y] > 0) return FALSE; 
return TRUE; 
} 
BOOLEAN KNIGHT::back_to_start() 
{ 
if (step == 1) return TRUE; 
else return FALSE; 
} 
BOOLEAN KNIGHT::is_end() 
{ 
if (step > width * width) return TRUE; 
else return FALSE; 
} 
void KNIGHT::set_start(int x, int y) 
{ 
curr_x = x; curr_y = y; step = 1; 
chessboard[x][y] = step; step = step + 1; 
direction[x][y] = MAX_DIR; 
last_direction = MAX_DIR; 
} 
BOOLEAN KNIGHT::select_direction() 
{ 
int try_x, try_y; 
// last_direction为MAX_DIR表示当前位置是一个新的位置，在新推进到某个位置(curr_x, curr_y)时， 
// direction[curr_x][curr_y]会记录上一位置到(curr_x, curr_y)时所选择的方向，这时 
// last_direction置为MAX_DIR用来标记该位置是新推进的位置。 
if (last_direction == MAX_DIR) last_direction = 0; 
else last_direction = last_direction + 1; 
while (last_direction < MAX_DIR) { 
// 看下一步推进到哪个位置是合法的，如果合法则选择该方向。 
try_x = curr_x + var_x[last_direction]; 
try_y = curr_y + var_y[last_direction]; 
if (is_legal(try_x, try_y)) break; 
last_direction = last_direction + 1; 
} 
if (last_direction == MAX_DIR) return FALSE; 
else return TRUE; 
} 
void KNIGHT::backward() 
{ 
step = step - 1; 
chessboard[curr_x][curr_y] = 0; 
// 将last_direction置为上一位置到(curr_x, curr_y)所选择的方向 
last_direction = direction[curr_x][curr_y]; 
// 根据这个方向回溯到上一位置，同时回溯到上一位置之后，在上一位置再试探时应该从 
// last_direction+1的方向开始。参看成员函数select_direction()。 
curr_x = curr_x - var_x[last_direction]; 
curr_y = curr_y - var_y[last_direction]; 
} 
void KNIGHT::forward() 
{ 
// 在推进时last_direction是当前位置所选择的方向 
curr_x = curr_x + var_x[last_direction]; 
curr_y = curr_y + var_y[last_direction]; 
chessboard[curr_x][curr_y] = step; 
step = step + 1; 
// 这个方向被记录下一位置(这时已经为(curr_x, curr_y))的direction数组中。 
direction[curr_x][curr_y] = last_direction; 
// last_direction的值已经被记录，这时置为MAX_DIR表示当前位置为新推进的位置 
last_direction = MAX_DIR; 
} 
BOOLEAN KNIGHT::tourist(int start_x, int start_y) 
{ 
init_chessboard(); 
set_start(start_x, start_y); 
do { 
if (select_direction()) forward(); 
else backward(); 
} while (!back_to_start() && !is_end()); 
if (back_to_start()) return FALSE; 
else return TRUE; 
} 
void KNIGHT::init_direction() 
{ 
var_x[0] = 2; var_y[0] = 1; 
var_x[1] = 1; var_y[1] = 2; 
var_x[2] = -1; var_y[2] = 2; 
var_x[3] = -2; var_y[3] = 1; 
var_x[4] = -2; var_y[4] = -1; 
var_x[5] = -1; var_y[5] = -2; 
var_x[6] = 1; var_y[6] = -2; 
var_x[7] = 2; var_y[7] = -1; 
} 
void KNIGHT::init_chessboard() 
{ 
int x, y, dir; 
for (x = 0; x < width; x = x + 1) { 
for (y = 0; y < width; y = y + 1) { 
chessboard[x][y] = 0; 
} 
} 
} 
int main() 
{ 
int width = 8; 
KNIGHT knight(width); 
int start_x, start_y; 
cout << "\nProgram begin...\n"; 
start_x = 4; start_y = 4; 
if (knight.tourist(start_x, start_y)) { 
knight.print(); 
}else { 
cout << "\nHave not found the solution for: "; 
cout << "Start: <" << start_x << ", " << start_y << ">, "; 
cout << "Width: " << width << "\n"; 
} 
return 1; 
} 

l 骑士游历问题的快速解
上面求解骑士游历问题的程序效率比较低，对于8×8的棋盘将花费相当长一段时间。为此我们可以在选择当前步的可能路线时增加一些启发式规则，使得这个选择从某种意义下来说是比较好的，从而加速问题的求解过程。 
对于骑士游历问题一个启发式规则是，在选择当前步的方向时去选择满足下面条件的方向，当按这个方向推进到下一位置时，这个位置所可以再选择的方向最少。也就是说在当前位置优先选一个走起来比?quot;艰难"的方向来推进。加入这种启发式规则之后，从运行的效果看，在求解的过程中几乎不回溯。 
为了使用这个启发式规则，我们首先要修改上面的成员函数select_direction()。这时在每个位置选择方向时不再是按照一定的顺序来选择，为了避免在回溯时重复选择方向，必需记住在某个位置哪些方向已经选择过了，我们使用三维数组cannot来记住这件事情，当其值为TRUE时表示某个位置的某个方向已经试探过了，为FALSE表示没有试探过。当从当前位置回溯到上一位置是，要先把当前位置所有方向的cannot值置为FALSE，因为下一次再到达这个位置时所有方向需要重新试探。 
为了研究加入启发式规则的效果，要求保留上面不使用启发式规则的程序，这样我们从KNIGHT类派生出一个类FAST_KNIGHT来支持快速求解骑士游历问题。在这个类中增加数组cannot，并且只需要重新定义select_direction(), backward()和forward()就可以了。需要重新定义backward()和forward()是因为在这两个成员函数中需要维护数组cannot的值。其它成员函数不用作任何的修改。我们在KNIGHT类中已经将这几个成员函数定义为虚函数，以便在成员函数tourist()中动态地选择这些函数来调用。读者需要学习完第八章多态性之后才能充分理解动态绑定的含义。 
在下面程序中，我们只给出类FAST_KNIGHT的定义，读者很容易修改演示程序以使用类FAST_KNIGHT来求解骑士游历问题。 

程序三：快速求解骑士游历问题的程序 

// 文件：FASTKNIGHT.CPP 
// 功能：使用回溯算法快速求解骑士游历问题 
class FAST_KNIGHT: public KNIGHT { 
public: 
FAST_KNIGHT(int width); 
protected: 
// FUNCTION: 初始化cannot数组 
void init_cannot(); 
// FUNCTION: 在当前位置根据启发式规则选择一个方向以推进到下一位置 
// RETURN: 如果可选择一个方向推进则返回TRUE，否则返回FALSE 
// NOTE: 重定义KNIGHT类的select_direction() 
virtual BOOLEAN select_direction(); 
// FUNCTION: 从当前位置回溯到上一位置，注意维持cannot数组 
// NOTE: 重定义KNIGHT类的backward() 
virtual void backward(); 
// FUNCTION: 从当前位置根据所选择的方向推进到下一位置 
// NOTE: 重定义KNIGHT类的forward() 
virtual void forward(); 
// 用来记住某个位置某个方向是否已经试探过 
BOOLEAN cannot[MAX_WIDTH][MAX_WIDTH][MAX_DIR]; 
}; 
FAST_KNIGHT::FAST_KNIGHT(int width): KNIGHT(width) 
{ 
init_cannot(); 
} 
void FAST_KNIGHT::init_cannot() 
{ 
int x, y, dir; 
for (x = 0; x < width; x = x + 1) 
for (y = 0; y < width; y = y + 1) 
for (dir = 0; dir < width; dir = dir + 1) cannot[x][y][dir] = FALSE; 
} 
BOOLEAN FAST_KNIGHT::select_direction() 
{ 
int try_x, try_y, next_x, next_y; 
int dir_index, next_index; 
int min_dir, count; 
min_dir = MAX_DIR; last_direction = MAX_DIR; 
for (dir_index = 0; dir_index < MAX_DIR; dir_index = dir_index + 1) { 
// 选择一个方向，使得根据该方向推进到下一位置时，在该位置可选的方向最少 
try_x = curr_x + var_x[dir_index]; 
try_y = curr_y + var_y[dir_index]; 
if (is_legal(try_x, try_y) && !cannot[curr_x][curr_y][dir_index]) { 
// 这个位置作为下一位置是合法，那么计算该位置可选的方向 
count = 0; 
for (next_index = 0; next_index < MAX_DIR; next_index++) { 
next_x = try_x + var_x[next_index]; 
next_y = try_y + var_y[next_index]; 
if (is_legal(next_x, next_y)) count = count + 1; 
} 
if (count < min_dir) { 
// 记录具有最少可选方向的下一位置 
last_direction = dir_index; 
min_dir = count; 
} 
} 
} 
if (last_direction == MAX_DIR) return FALSE; 
else return TRUE; 
} 
void FAST_KNIGHT::backward() 
{ 
int dir; 
step = step - 1; 
chessboard[curr_x][curr_y] = 0; 
// 从位置(curr_x, curr_y)回溯，那么下一次再到达该位置时所有方向都需要重新试探 
for (dir = 0; dir < MAX_DIR; dir = dir + 1) cannot[curr_x][curr_y][dir] = FALSE; 
last_direction = direction[curr_x][curr_y]; 
curr_x = curr_x - var_x[last_direction]; 
curr_y = curr_y - var_y[last_direction]; 
} 
void FAST_KNIGHT::forward() 
{ 
// 该位置的这个方向已经试探过了 
cannot[curr_x][curr_y][last_direction] = TRUE; 
curr_x = curr_x + var_x[last_direction]; 
curr_y = curr_y + var_y[last_direction]; 
chessboard[curr_x][curr_y] = step; 
step = step + 1; 
direction[curr_x][curr_y] = last_direction; 
last_direction = MAX_DIR; 
} 

l 思考与提高 
在充分理解上述三个程序之后，读者可进一步思考下述问题： 
1.上述求解八皇后问题的程序中数组board不是必须的，因为根据solution数组完全可算出哪个位置有皇后，修改上述程序使得不需要数组board而给出八皇后问题的所有解。 
2.思考快速求解骑士游历问题中的启发式规则为什么能够使得在求解过程中几乎不回溯。进一步类比该启发式规则，考虑在求八皇后问题的一个解时可利用怎样的启发式规则以加速求解过程。 
3.使用回溯算法求解迷宫问题，自己给出迷宫问题的进一步陈述，设计所需要的数据结构，并细化上述回溯算法。 
4.理解上述快速求解骑士游历问题的程序，体会在设计算法时的自顶向上分解、逐步求精的思想，进一步体会使用面向对象程序设计思想，特别是利用动态绑定的好处。
