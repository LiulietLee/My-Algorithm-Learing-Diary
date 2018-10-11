struct KM
{
    int w[maxn][maxn];
    int n,m;
    int lx[maxn],ly[maxn];
    bool vx[maxn],vy[maxn];
    int left[maxn];
    int delta;
    int slack[maxn];

    bool match(int i,int flag)
    {
        vx[i] = true;
        rep(j,1,m+1)if(!vy[j])
        {
            if(lx[i]+ly[j]==w[i][j])//相等子图
            {
                vy[j] = true;
                if(left[j] == 0 || match(left[j],flag))
                {
                    if(flag) left[j] = i;
                    return true;
                }
            }
            else slack[j] = min(slack[j],lx[i]+ly[j]-w[i][j]);
        }
        return false;
    }

    int km(int n,int m)
    {
        this->n = n;
        this->m = m;
        memset(left,0,sizeof left);
        ms(ly);
        rep(i,1,n+1)
        {
            lx[i] = -inf;
            
            rep(j,1,m+1)
                lx[i] = max(lx[i],w[i][j]);
        }

        rep(i,1,n+1)
        {
            rep(j,1,m+1)slack[j] = inf;
            ms(vx),ms(vy);
            if(match(i,1))continue;//增广路

            bool ok = true;
            while(ok)
            {   
                int  d = inf;
                rep(j,1,m+1)if(!vy[j] && d>slack[j])
                    d = slack[j];
                
                rep(j,1,n+1)if(vx[j])
                    lx[j] -= d;

                int p;
                rep(j,1,m+1)    
                if(vy[j])ly[j]+=d;
                else 
                {
                    slack[j] -= d;
                    if(slack[j] == 0)
                        p = j;
                }   

                // rep(i,1,n+1)
                // {
                //  if(!vy[i] && slack[i] == 0)
                //  {
                //      vy[i] = true;
                //      if(left[i] == 0 || match(left[i],0))
                //      {
                //          ok = false;
                //          break;
                //      }
                //  }
                // }
             
                vy[p] = true;
                if(left[p] == 0 || match(left[p],0))
                {
                    ok = false;//招到合适的右端点，使得可以继续增广
                }
            
            }
            ms(vx),ms(vy);
            match(i,1);     
        }
        int ans = 0;
        rep(i,1,m+1)if(left[i])
        {   
       		ans+=w[left[i]][i];         
        }
        return ans;
    }
}km;