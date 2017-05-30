#include "rank.h"
#include <string>

Rank::Rank()
{
    rankFile.setFileName("/home/pd2vm/2017-pd2-project-2-F44026220-1/Rank/Rank.txt");
    out.setDevice(&rankFile);
    out.setCodec("UTF-8");
    in.setDevice(&rankFile);
    in.setCodec("UTF-8");
}

void Rank::write(QString newName, int newTime)
{
    int i, j, bufTime, oldTime;
    QString bufName, oldName;

    bufTime=newTime;
    bufName=newName;
    for (i=0; i<PlayerNum; ++i) {
        if (Time[i]<newTime) {
           for (j=i; j<PlayerNum; ++j) {
               oldTime=Time[j];
               oldName=Name[j];
               Time[j]=bufTime;
               Name[j]=bufName;
               bufTime=oldTime;
               bufName=oldName;
              }
           break;
          }
       }
    if (PlayerNum<RANKNUM) {
       Time[PlayerNum]=bufTime;
       Name[PlayerNum]=bufName;
      }

    if (!rankFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
        return;

    if (PlayerNum<RANKNUM)
        for (i=0; i<PlayerNum+1; ++i)
            out<<Name[i]<<'\t'<<Time[i]<<endl;
    else
        for (i=0; i<RANKNUM; ++i)
            out<<Name[i]<<'\t'<<Time[i]<<endl;

    rankFile.close();
}

void Rank::read()
{
    int count;
    QString currentLine;

    if (!rankFile.open(QIODevice::ReadOnly))
        return;

    count=0;
    while (!in.atEnd() && count<=RANKNUM) {
       in>>Name[count]>>Time[count];
       ++count;
       currentLine=in.readLine();
       if (currentLine.isNull())
           break;
      }
    PlayerNum=count;

    rankFile.close();
}
