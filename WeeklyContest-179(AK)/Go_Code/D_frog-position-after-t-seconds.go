package ttt

func frogPosition(n int, edges [][]int, time int, target int) (ans float64) {
	g := make([][]int, n)
	g[0] = append(g[0], -1) // 小技巧：加一条根到 -1 的边
	for _, e := range edges {
		v, w := e[0]-1, e[1]-1
		g[v] = append(g[v], w)
		g[w] = append(g[w], v)
	}
	target--
	var dfs func(v, fa, t int, p float64)
	dfs = func(v, fa, t int, p float64) {
		if v == target && (t == 0 || t > 0 && len(g[v]) == 1) {
			// 找到了目标，并且用完了时间或者在时间用完前到了叶结点
			ans = p
		}
		for _, w := range g[v] {
			if w != fa {
				dfs(w, v, t-1, p/float64(len(g[v])-1))
			}
		}
	}
	dfs(0, -1, time, 1)
	return
}
