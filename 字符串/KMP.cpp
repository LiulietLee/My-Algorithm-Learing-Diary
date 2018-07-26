int my_next[MAXN], n;

void getNext(char str[], int len)
{
	int j = -1;
	my_next[0] = -1;
	for(int i=1;i<len;i++){
		while(j != -1 && str[i] != str[j+1]){
			j = my_next[j];
		}
		if(str[i] == str[j+1]){
			j++;
		}
		my_next[i] = j;
	}
}

/// len - my_next[len] = ��Сѭ���ڳ���
int getMinRep(char s[])
{
    int len=strlen(s);
    getNext(s,len);
    int min_repetend=len - my_next[len];
    if(len % min_repetend == 0 && len != min_repetend)
        return min_repetend;
    else
        return len;
}

/*
	����������ͳ�ƴ����Ļ���ֻ�ð���ans����ȡ����ע�;ͺ��ˣ���
*/
bool kmp(char text[], char pattern[])
{

	// int lastPos = -1;
	// int ans = 0;
	int n = (int)strlen(text);
	int m = (int)strlen(pattern);
	getNext(pattern, m);
	int j = -1;
	for(int i=0;i<n;i++){
		while(j != -1 && text[i] != pattern[j+1]){
			j = my_next[j];
		}
		if(text[i] == pattern[j+1]){
			// if(lastPos < i) lastPos = i;
			j++;
		}
		if(j == m-1){//����ƥ�䣬�����
			// ans++;
			// j = my_next[j];
			// return lastPos - m + 2;//�״γ��ֵ�λ��
			return true;//�Ƿ����
		}
	}
	// return ans;//����һ��ƥ������˼���
	return false;
}

int main(void)
{
	char text[] = "abababaabc";
	char pattern[] = "ababaab";
	kmp(text, pattern);
	return 0;
}
