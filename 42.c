int trap(int* height, int heightSize) {
    int s=0,l=0,m=0,m1=0,ans = 0;
    for(int i=0;i<heightSize;++i){
        if(height[i] >=m){
            ans += l*m-s;
            l = 0;
            m =height[i];
            s = 0;
        }else{
            l+=1;
            s+=height[i];
        }
    }
    s = 0;
    l = 0;
    m1 = 0;
    for(int i=heightSize-1;i>=0;--i){
        if(height[i]>=m1){
            ans += l*m1-s;
            l = 0;
            m1=height[i];
            s = 0;
        }else{
            l+=1;
            s+=height[i];
        }
        if(m==m1){
            break;
        }
    }
    return ans;
}
