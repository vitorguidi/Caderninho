int mergesort(vector<int> &v){
	
	int tam=v.size();
	if(tam==1)	return 0;
	
	vector<int> v1,v2;
	for(int i=0;i<tam/2;i++)	v1.pb(v[i]);
	for(i==tam/2;i<tam;i++)		v2.pb(v[i]);
	
	int inv=0;
	inv+=mergesort(v1);
	inv+=mergesort(v2);
	
	v1.pb(INF);
	v2.pb(INF);
	
	int ini1=0 , ini2=0, s=v1.size();
	
	for(int i=0;i<tam;i++){
		
		if(v1[ini1]<=v2[ini2]){
			v[i]=v1[ini1];
			ini1++;
		}

		else{
			v[i]=v2[ini2];
			ini2++;
			inv+=s-1-ini1;
		}
	}

	return inv;

}