#include "score.h"

//初始化
void InitScoreList(ScoreList* scorelist)
{
    assert(scorelist);
    scorelist->count = 0;
    scorelist->head = (ScoreNode*)malloc(sizeof(ScoreNode));
    if(scorelist->head == NULL )
    {
        printf("%s\n",strerror(errno));
        return;
    }
    scorelist->count = 0;
    scorelist->head->next = NULL;
    scorelist->head->data.id = 0;
    strcpy(scorelist->head->data.student_id,"");
    strcpy(scorelist->head->data.academic_year,"0");
    strcpy(scorelist->head->data.semester,"0");
    scorelist->head->data.calculus_score = 0;
    scorelist->head->data.linear_algebra_score = 0;
    scorelist->head->data.politics_score = 0;
    scorelist->head->data.english_score = 0;
    scorelist->head->data.PE_score = 0;
    scorelist->head->data.comprehensive_score = 0;
    strcpy(scorelist->head->data.notes,"0");
    strcpy(scorelist->head->data.record_date,"0");
}



//获取日期
void GetCurrentDate(char *date)
{
    time_t now = time(NULL);
    struct tm*local_time = localtime(&now);
    strftime(date,26,"%Y-%m-%d",local_time);
}

//计算综合成绩
double CalcComprehensiveScore(double calculus, double linear_algebra,
                             double PE, double politics,double english)
{
    return 0.2*calculus+0.2*linear_algebra+0.2*PE+0.2*politics+0.2*english;
}


//插入
int AddScore(ScoreList* scorelist,StudentScore new_score)
{
    assert(scorelist);
    ScoreNode *newnode = (ScoreNode *)malloc(sizeof(ScoreNode));
    if(newnode == NULL)
    {
        printf("%s\n",strerror(errno));
     
        return -1;//失败
    }
    //成绩单里无内容
    if(scorelist->head->next == NULL)
    {
        newnode->data = new_score;
        scorelist->head->next = newnode;
        newnode->next = NULL;
        (scorelist->count)++;
        newnode->data.id = scorelist->count;
        GetCurrentDate(newnode->data.record_date); 
        return 0;//成功
    }
    //成绩单里有内容，需判断是否重复
    ScoreNode*pr = scorelist->head->next;
    while(pr != NULL)
    {
        //若内容重复
        if((strcmp(pr->data.student_id,new_score.student_id) == 0)
            &&(strcmp(pr->data.academic_year,new_score.academic_year) == 0)
            &&(strcmp(pr->data.semester,new_score.semester) == 0))
        {
            free(newnode);
            return 1;//记录重复
        }  
        pr = pr->next; 
    }
    //内容不重复
        newnode->data = new_score;
        newnode->next = NULL;
        pr = scorelist->head;
        while(pr->next != NULL)
        {
            pr = pr->next;
        }
        pr->next = newnode;
        (scorelist->count)++;
        newnode->data.id = scorelist->count;
        GetCurrentDate(newnode->data.record_date);
        return 0;//成功
}


//删除
int DeleteScoreByStuYearSem(ScoreList*scorelist, const char *student_id, 
                        const char *academic_year,const char *semester)
{
    assert(scorelist);
    if(scorelist->head->next == NULL)
    {
        return -1;//未找到记录
    }
    ScoreNode*pdeletenode = scorelist->head->next;
    ScoreNode*ppre = scorelist->head;
    ppre->next = pdeletenode;
    while(pdeletenode !=NULL)
    {
        if((strcmp(pdeletenode->data.student_id,student_id) == 0)
        &&(strcmp(pdeletenode->data.academic_year,academic_year) == 0)
        &&(strcmp(pdeletenode->data.semester,semester) == 0))
            {
                
                ppre->next = pdeletenode->next;
                free(pdeletenode);
                scorelist->count--;
                while(ppre->next != NULL)
                {
                    ppre->next->data.id--;
                    ppre = ppre->next;
                }
                return 0;//成功
            
            }
            ppre = ppre->next;
            pdeletenode = pdeletenode->next;
    }
    return -1;//未找到记录
}   



//更改
int UpdateScore(ScoreList*scorelist, const char *student_id, const char *academic_year,
                const char *semester, StudentScore updateInfo)
{
    assert(scorelist);
    assert(student_id);
    assert(academic_year);
    assert(semester);
    if(scorelist->count == 0)
    {
        return -1;//未找到记录
    }
    ScoreNode*pupdatenode = scorelist->head->next;
    while(pupdatenode != NULL)
    {
        if((strcmp(pupdatenode->data.student_id,student_id) == 0)
        &&(strcmp(pupdatenode->data.academic_year,academic_year) == 0)
        &&(strcmp(pupdatenode->data.semester,semester) == 0))
        {
            pupdatenode->data = updateInfo;
            return 0;
        }
        pupdatenode = pupdatenode->next;
    }
    return -1;//未找到记录
}


//打印单条成绩
void PrintStudentScores(StudentScore*score)
{
    assert(score);
    printf("%-2s\t%-20s\t%-20s\t%-10s\t%-20s\t%-25s\t%-20s\t%-20s\t%-20s\t%-25s\t%-26s\n",
    "ID","student id","academic year","semester","calculus score","linear algebra score",
    "english score","politics score","PE score","comprehensive score","record date");
    printf("%-2d\t%-20s\t%-20s\t%-10s\t%-20.2f\t%-25.2f\t%-20.2f\t%-20.2f\t%-20.2f\t%-25.2f\t%-26s\n",
    score->id,score->student_id,score->academic_year,score->semester,score->calculus_score,score->linear_algebra_score,
    score->english_score,score->politics_score,score->PE_score,score->comprehensive_score,score->record_date);
}

//打印多条成绩
void PrintScoreList(ScoreList*student, const char *student_id)
{
    assert(student);
    printf("%s的所有成绩\n",student_id);
    printf("%-2s\t%-20s\t%-20s\t%-10s\t%-20s\t%-25s\t%-20s\t%-20s\t%-20s\t%-25s\t%-26s\n",
    "ID","student id","academic year","semester","calculus score","linear algebra score",
    "english score","politics score","PE score","comprehensive score","record date");
    if(student->head->next == NULL)
    return;
    ScoreNode*score  =  student->head->next;
    while(score != NULL)
    {
        printf("%-2s\t%-20s\t%-20s\t%-10s\t%-20s\t%-25s\t%-20s\t%-20s\t%-20s\t%-25s\t%-26s\n",
        score->data.id,score->data.student_id,score->data.academic_year,score->data.semester,score->data.calculus_score,score->data.linear_algebra_score,
    score->data.english_score,score->data.politics_score,score->data.PE_score,score->data.comprehensive_score,score->data.record_date);
           score = score->next; 
    }
    return ;
}


//查找一条成绩记录
StudentScore* QuerySingleScore(ScoreList*scorelist,const char *student_id,   
                              const char *academic_year,const char *semester)
{
    assert(scorelist);
    ScoreNode*ptarget = scorelist->head;
    if(scorelist->count == 0)
    {

        return NULL;//无记录
    }
    ptarget = scorelist->head->next;
    while(ptarget != NULL)
    {
        if((strcmp(ptarget->data.student_id,student_id) == 0)
        &&(strcmp(ptarget->data.academic_year,academic_year) == 0)
        &&(strcmp(ptarget->data.semester,semester) == 0))
        {
            return &(ptarget->data);
        }
        ptarget = ptarget->next;
    }
}                          
                              



//查找一个学生所有成绩
ScoreList*  QueryScoresByStuId(ScoreList*scorelist, const char *student_id)
{
    assert(scorelist);
    assert(student_id);
    ScoreList*studentlist = (ScoreList*)malloc(sizeof(ScoreList));
    if(studentlist == NULL)
    {
        printf("%s\n",strerror(errno));
        return NULL;
    }
    InitScoreList(studentlist);
    ScoreNode* p = scorelist->head->next;
    ScoreNode*r = studentlist->head;
    int i = 1;
    while(p != NULL)
    {
        if(strcmp(p->data.student_id,student_id) == 0)
        {
            ScoreNode*pnewnode  = (ScoreNode*)malloc(sizeof(ScoreNode));
            pnewnode->data = p->data;
            pnewnode->data.id = i;
            r->next = pnewnode;
            r = r->next;
            i++;
        }
        p = p->next;

    } 
    return studentlist;
}

//释放链表
void FreeScoreList(ScoreList*scorelist)
{
  if(scorelist == NULL)
  {
    return;
  }
  ScoreNode*p = scorelist->head;
  ScoreNode*tem = NULL;
  while(p != NULL)
  {
    tem = p;
    p = p->next;
    free(tem);
  }
  free(scorelist);
  

}