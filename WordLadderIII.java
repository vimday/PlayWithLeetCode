
/*
 * @Author :vimday
 * 
 * @Desc : 单词接龙3
 * 
 * @Url :https://www.jianshu.com/p/1aeef1567d5a?tdsourcetag=s_pctim_aiomsg
 * 
 * @File Name :WordLadderIII.java
 * 
 * @Created Time:2020-03-15 17:07:10
 * 
 * @E-mail :lwftx@outlook.com
 * 
 * @GitHub :https://github.com/vimday
 */
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class WordLadderIII {

    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);
        while (scan.hasNext()) {
            int n = scan.nextInt();
            String[] arr = new String[n];
            for (int i = 0; i < n; i++)
                arr[i] = scan.next();
            System.out.println(WordListOrder.canArrangeWords(n, arr));
        }
        scan.close();
    }

}

class WordListOrder {

    public static String canArrangeWords(int n, String[] arr) {
        for (String s : arr)
            System.out.println(s);
        // 26个英文字母看作26个点,用整数0-25来表示
        int[][] directedGraph = new int[26][26];// 邻接矩阵表示有向图
        int[] inDegree = new int[26]; // 顶点入度
        int[] outDegree = new int[26]; // 顶点出度
        boolean[] hasLetter = new boolean[26]; // 标记字母是否出现过
        boolean hasEuler = true; // 有狭义欧拉路径或欧拉回路标志
        for (int i = 0; i < n; i++) {
            String word = arr[i];
            char firstLetter = word.charAt(0);
            char lastLetter = word.charAt(word.length() - 1);
            outDegree[firstLetter - 'a']++;
            inDegree[lastLetter - 'a']++;
            directedGraph[firstLetter - 'a'][lastLetter - 'a'] = 1; // 有向图
            hasLetter[firstLetter - 'a'] = true;
            hasLetter[lastLetter - 'a'] = true;
        }
        int startNum = 0;
        int endNum = 0;
        for (int vertex = 0; vertex < 26; vertex++) {
            if (outDegree[vertex] - inDegree[vertex] == 1) // 起点
                startNum++;
            if (inDegree[vertex] - outDegree[vertex] == 1) // 终点
                endNum++;
            if (Math.abs(inDegree[vertex] - outDegree[vertex]) > 1) {
                hasEuler = false;
                break;
            }
        }
        boolean isEulerPath = (startNum == 1 && endNum == 1); // 这里指狭义上的欧拉路径，不包括欧拉回路
        boolean isEulerCircuit = (startNum == 0 && endNum == 0);// 欧拉回路
        if ((!isEulerPath) && (!isEulerCircuit)) // 既不是欧拉路径也不是欧拉回路
            hasEuler = false;
        // 判断是否弱连通
        int vertexNum = 0; // 统计图中点的个数
        for (int letter = 0; letter < 26; letter++) {
            if (hasLetter[letter])
                vertexNum++;
        }
        int firstWordFirstLetter = arr[0].charAt(0) - 'a';// 以第一个单词的首字母作为起点进行BFS
        hasEuler = hasEuler && isConnected(firstWordFirstLetter, vertexNum, directedGraph);
        if (hasEuler)
            return "Yes";
        else
            return "No";
    }

    // 判断有向图是否弱连通，即转换成无向图判断是否连通
    public static boolean isConnected(int start, int vertexNum, int[][] directedGraph) {
        int[][] undirectedGraph = new int[26][26];
        for (int i = 0; i < 26; i++) // 把有向图转换成无向图
        {
            for (int j = 0; j < 26; j++) {
                if (directedGraph[i][j] == 1) {
                    undirectedGraph[i][j] = 1;
                    undirectedGraph[j][i] = 1;
                }
            }
        }
        Queue<Integer> queue = new LinkedList<Integer>();
        boolean[] passedVertex = new boolean[26];
        int passedVertexNum = 0;
        queue.offer(start);
        // 从起点开始进行BFS，统计遍历到点的个数
        while (!queue.isEmpty()) {
            int currentVertex = queue.poll();
            passedVertex[currentVertex] = true;
            passedVertexNum++;
            for (int vertex = 0; vertex < 26; vertex++) {
                if (undirectedGraph[currentVertex][vertex] == 1 && passedVertex[vertex] == false)
                    queue.offer(vertex);
            }
        }
        // 遍历到所有的点，证明无向图是连通的
        if (passedVertexNum == vertexNum)
            return true;
        else
            return false;
    }
}