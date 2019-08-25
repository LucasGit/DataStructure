
// normal match 
int NormalStringMatch(char *pSrc,char *pTarget)
{

	int i = 0;
	int j = 0;
	int SLen - strlen(pSrc);
	int TLen - strlen(pTarget);

	while(i<=SLen && j<=TLen)
	{
		if((pSrc[i] == pTarget[j]))
		{
			j++
		}
		else
		{
			j = 0;
		}

		i++;
	}

	// string matched postion in src string 
	if(j>TLen)
	{
		return i-j;
	}
	else
	{
		//
		return -1;
	}
}

