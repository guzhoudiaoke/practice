package main

import (
	"container/list"
	"fmt"
)

type Item struct {
	value int
	depth int
}

type Queue struct {
	data *list.List
}

func NewQueue() *Queue {
	q := new(Queue)
	q.data = list.New()
	return q
}

func (q *Queue) Enqueue(v interface{}) {
	q.data.PushBack(v)
}

func (q *Queue) Dequeue() interface{} {
	iter := q.data.Front()
	v := iter.Value
	q.data.Remove(iter)
	return v
}

func (q *Queue) Dump() {
	for iter := q.data.Front(); iter != nil; iter = iter.Next() {
		fmt.Println("item:", iter.Value)
	}
}

func (q *Queue) Empty() bool {
	return q.data.Len() == 0
}

func solve(n, m int) int {
	if n >= m {
		return n - m
	}

	len := m*2 + 1
	graph := make([][]int, len, len)
	for i := 0; i < m*2+1; i++ {
		graph[i] = make([]int, 2, 2)
	}

	for i := 1; i < len; i++ {
		graph[i][0] = i - 1
		graph[i][1] = i * 2
	}

	ans := 0
	visit := make([]bool, len, len)
	q := NewQueue()
	q.Enqueue(Item{value: n, depth: 0})
	for !q.Empty() {
		v := q.Dequeue().(Item)
		if v.value == m {
			ans = v.depth
			break
		}

		visit[v.value] = true
		val := v.value
		if graph[val][0] > 0 && graph[val][0] < len && !visit[graph[val][0]] {
			it := Item{value: graph[val][0], depth: v.depth + 1}
			q.Enqueue(it)
		}

		if graph[val][1] > 0 && graph[val][1] < len && !visit[graph[val][1]] {
			it := Item{value: graph[val][1], depth: v.depth + 1}
			q.Enqueue(it)
		}
	}

	return ans
}

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	fmt.Println(solve(n, m))
}
