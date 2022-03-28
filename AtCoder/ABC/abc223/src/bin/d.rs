use proconio::input;
use proconio::marker::Usize1;
use std::collections::BinaryHeap;
use std::cmp::Reverse;

fn main() {
    input! {
        n :usize,
        m :usize,
        ab: [(Usize1, Usize1); m]
    }
    let mut g = vec![vec![]; n];
    let mut cnt = vec![0; n];
    for (a, b) in ab {
        g[a].push(b);
        cnt[b] += 1;
    }
    let mut pq = BinaryHeap::new();
    let mut ans = vec![];
    for i in 0..n {
        if cnt[i] == 0 {pq.push(Reverse(i));}
    }
    while let Some(Reverse(u)) = pq.pop() {
        ans.push(u+ 1);
        for &v in g[u].iter() {
            cnt[v] -= 1;
            if cnt[v] == 0 {pq.push(Reverse(v));}
        }
    }
    if(ans.len() == n){
        for &v in ans.iter() {print!("{} ", v);}
        print!("\n");
    }else{
        println!("-1");
    }
}
