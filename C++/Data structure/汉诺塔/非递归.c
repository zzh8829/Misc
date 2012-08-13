void main();

#include <stdio.h>

#define width (rings+1)

void main()
{
  int rings, last, next, x, z[500], s[3];

  printf("how many rings?  "); scanf("%d",&rings);

  for(x=1; x<=rings; x++)  /* put rings on first peg */
      z[x]=width-x;
  for(x=0; x<=2*width; x+=width)  /* set base for each peg  */
      z[x]=1000;

/* if even number of rings, put first ring on second peg; if odd, on third */

  if(rings%2==0)
      {
      last=1; s[2]=0; s[1]=1;
      z[width+1]=z[rings];
      }
  else
      {
      last=2; s[1]=0; s[2]=1;
      z[2*width+1]=z[rings];
      }

  printf("from 1 to %d\n",last+1); s[0]=rings-1;

  while(s[0]+s[1])  /* while first and second pegs aren't empty */
      {
/* next ring to move is smaller of rings on the two pegs not moved onto last */

      if(last==0)  next=z[width+s[1]]<z[2*width+s[2]]?1:2;
      if(last==1)  next=z[s[0]]<z[2*width+s[2]]?0:2;
      if(last==2)  next=z[s[0]]<z[width+s[1]]?0:1;

/* top ring of 'to' peg must be larger and an even 'distance' away */

      if((z[next*width+s[next]])>(z[last*width+s[last]])||((z[last*width+s[last]]-z[next*width+s[next]])%2==0))
		last=3-next-last;

      printf("from %d to %d\n",next+1,last+1);

      s[next]=s[next]-1; s[last]=s[last]+1; /* move from 'next' to 'last' peg */
      z[last*width+s[last]]=z[next*width+s[next]+1];
      }
}
