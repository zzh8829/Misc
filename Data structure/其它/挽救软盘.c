 软盘的FAT表(文件分配表)被损坏时,计算机就不能从软盘上读取数据。 
但是,在软盘中有两份完全相同的文件分配表,而DOS在读文件时并不使用 
第二张文件分配表,因此,它被损坏的可能性较低。在计算机提示FAT表损 
坏时,利用第二张分配表重写第一张文件分配表,往往能成功地挽回你的软 
盘上的数据。文件分配表在磁盘中的具体位置及长度视磁盘的规格不同而 
不同。 
    本文提供的程序,用Turbo C 2.0编写,于Dos6.22,UCDOS 3.1下通过。 
按照程序的提示,可方便地完成这一工作。 
    #include [dos.h] 
    main () 
      {int i,j,dh,ch; 
      a: printf ("Select drive/选定驱动器: (0->A/1->B) \n"); 
      scanf(" %d",&ch); 
      if (1       goto a; 
      printf ("Slect disk/选定磁盘类型:"); 
    printf(" (36->360KB/72->720KB/12->1.2MB/14->1.44MB) \n"); 
      scanf(" %d" ,&dh);/*按选定的软盘类型进行处理*/ 
      switch (dh) 
      {case 36:/*处理360KB软盘*/ 
        for (i=1; i<3;i++) 
         {j=j+2 
           absread(ch,1,j,0); 
           abswrite (ch,1,i,0);} 
         break; 
       case 72: /*处理720KB软盘*/ 
         for (i=1; i<4; i++) 
           {j=i+3; 
            absread (ch,1,j,0); 
            abswrite(ch,1,i,0);} 
         break; 
       case 12: /*处理1.2MB软盘*/ 
         for (i=1; i<8; i++) 
            {j=i+7; 
             absread (ch,1,j,0); 
             abswrite (ch,1,i,0); 
            } 
         break; 

       case 14: /*处理1.44MB软盘*/ 
         for (i=1; i<10; i++) 
            { 
             j=i+9; 
             absread (ch,1,j,0); 
             abswrite (ch,1,i,0); 
            } 
         break; 
        } 
        printf ("OK!"); 
      } 