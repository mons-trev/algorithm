import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Vector;

class Cord{
	int first, second;
	public Cord(int first, int second) {
		this.first=first;
		this.second= second;
	}
}
public class Main {
	static boolean rows[][] = new boolean [9][10];
	static boolean cols[][] = new boolean [9][10];
	static boolean areas[][] = new boolean [9][10];
	static Vector<Cord> blank_cord = new Vector<>();
	
	static int find_area(int i, int j) {
		return 3*(i/3)+j/3;
	}
	
	static boolean backtracking(int k, int l, int [][] answer) {
		if(k==l) return true;
		int x=blank_cord.get(k).first;
		int y=blank_cord.get(k).second;
		int a= find_area(x,y);
		
		for(int num=1; num<10; num++) {
			if(rows[x][num]==false&&cols[y][num]==false&&areas[a][num]==false) {
				rows[x][num]=true;
				cols[y][num]=true;
				areas[a][num]=true;
				
				answer[x][y] = num;
				if(backtracking(k+1, l, answer)) {
					return true;
				}
				else {
					rows[x][num]=false;
					cols[y][num]=false;
					areas[a][num]=false;
				}
			}
		}
		return false;
	}
	
	public static int[][] solution(int sudoku[][]){
        int [][] answer = new int [9][9];// 정답 = 현재의 상태를 저장하는 배열
        
        for(int i=0; i<9; i++) {
        	for(int j=0; j<9; j++) {
        		if(sudoku[i][j]==0) {
        			blank_cord.add(new Cord(i,j));
        		}
        		else {
        			rows[i][sudoku[i][j]]=true;
        			cols[j][sudoku[i][j]]=true;
        			areas[find_area(i,j)][sudoku[i][j]]=true;
        			answer[i][j]= sudoku[i][j];
        		}
        	}
        }
        int l= blank_cord.size();
        backtracking(0,l,answer);
        return answer;
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int sudoku[][] = new int[9][9];
		for (int i=0; i<9; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine()," ");
			for (int j=0; j<9; j++) sudoku[i][j] = Integer.parseInt(st.nextToken());
		}
		int answer[][] = solution(sudoku);
		for (int i=0; i<9; i++) {
			for (int j=0; j<9; j++) System.out.print(answer[i][j]+" ");
			System.out.println();
		}
	}
}
