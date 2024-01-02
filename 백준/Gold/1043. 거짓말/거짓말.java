
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	static int find(int x) {
		if(parent[x]==x) return x;
		else return find(parent[x]); 
	}
	static boolean union(int a, int b){
		int aroot=find(a);
		int broot=find(b);

		if(aroot==broot) return false;
		else {
			if(a>b) parent[aroot]=broot;
			else parent[broot]=aroot;
			
			return true;
		}
		
	}
	
	static int parent[];
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc= new Scanner(System.in);
		int N=sc.nextInt();
		parent=new int[N+1];
		boolean knowtrue[]=new boolean[N+1];
		int M=sc.nextInt();
		int knowing=sc.nextInt();

		for(int i=0; i<N+1; i++) {
			parent[i]=i;//parent
		}
		
		
		for(int i=0; i<knowing; i++) {
			knowtrue[sc.nextInt()]=true;
		}
		ArrayList<Integer> party[]= new ArrayList[M];
		int a=0;
		int pre=0, cur;
		while(a<M) {
			int num=sc.nextInt();				
			party[a]=new ArrayList<>();

			if(num>0) {
				pre=sc.nextInt();
				party[a].add(pre);
			}
			for(int j=1; j<num; j++) {
				cur=sc.nextInt();
				party[a].add(cur);
				union(pre,cur);
				pre=cur;
			}
						
			a++;
		}
		
		for(int i=0; i<N+1; i++) {
			if(knowtrue[i]==true) {
				knowtrue[find(i)]=true;
			}
		}
		
		int ans=0;
		int p=0;
		for(int i=0; i<M; i++) {
			if(party[i].size()>0) {
				p= find(party[i].get(0));
				if(knowtrue[p]==false) 
					{
					ans++;
					}
			}
		}
		System.out.println(ans);
		
	}
	
	

}
