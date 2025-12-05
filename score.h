#include <stdio.h>
#include <string.h>
#include <time.h> 
#include <stdlib.h>
#include <errno.h>
#include <assert.h>

//一条成绩信息
typedef struct {
    int id;                      // 主键：自增整数
    char student_id[20];         // 关联学生ID
    char academic_year[16];      // 学年（比如"2024-2025"）
    char semester[3];            // 学期（比如"1"或"2"）
    double calculus_score;       // 微积分成绩   DECIMAL(5,2)
    double linear_algebra_score; // 线性代数成绩
    double english_score;        // 四级成绩
    double politics_score;       // 政治成绩
    double PE_score;             //体测成绩
    double comprehensive_score;  // 综合成绩
    char record_date[26];         // 记录日期（默认当前时间)
    char notes[200];             // 备注信息
} StudentScore;

//链表节点结构
typedef struct ScoreNode {
    StudentScore data;      // 节点存储的成绩数据
    struct ScoreNode* next; // 指向下一个节点的指针
} ScoreNode;


// 链表的头结构（管理链表）
typedef struct {
    ScoreNode* head; // 链表头节点
    int count;       // 当前已记录的学生人数
} ScoreList;


//函数声明
void InitScoreList(ScoreList* scorelist);  //链表的初始化
int AddScore(ScoreList* scorelist,StudentScore new_score);  //增添一条成绩记录，
                                              //向链表中添加单条成绩记录，自动检查“学生ID+学年+学期”的唯一性，
                                              //自动生成自增ID；返回0=成功，1=记录重复，-1=失败
int DeleteScoreByStuYearSem(ScoreList*scorelist, 
                            const char *student_id, 
                            const char *academic_year, //根据“学生ID+学年+学期”匹配成绩记录，从链表中删除对应节点；
                            const char *semester);     //返回0=成功，-1=未找到记录
int UpdateScore(ScoreList*scorelist, 
                const char *student_id, 
                const char *academic_year, 
                const char *semester, //根据“学生ID+学年+学期”匹配记录，更新其科目分数、备注等信息；
                StudentScore updateInfo);//返回0=成功，-1=未找到记录
ScoreList*  QueryScoresByStuId(ScoreList*scorelist, const char *student_id);//查找一名学生的所有成绩记录
                                                                   //根据学生ID查询其所有成绩记录
                                                                   //返回包含这些记录的临时链表（需自行释放）；返回NULL=无记录
StudentScore* QuerySingleScore(ScoreList*scorelist, 
                              const char *student_id,   //查找一条成绩记录
                              const char *academic_year,//根据“学生ID+学年+学期”查询单条成绩记录，
                              const char *semester);    //返回对应节点指针；返回NULL=未找到
double CalcComprehensiveScore(double calculus, double linear_algebra,//计算综合成绩
                             double PE, double politics,double english);     
void GetCurrentDate(char *date); //获取系统当前日期
                                 //格式为“YYYY-MM-DD”，存入传入的date字符数组（需提前分配至少20字节内存）  
void PrintStudentScores(StudentScore*score); //打印单条成绩记录,输出单条成绩记录的所有字段（如ID、学生ID、各科目成绩等）
void PrintScoreList(ScoreList*student, const char *student_id);  //打印多条成绩记录 
void FreeScoreList(ScoreList*scorelist);//释放链表   





