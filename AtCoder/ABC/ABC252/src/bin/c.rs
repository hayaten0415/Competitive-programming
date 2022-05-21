use proconio::input;

fn main() {
  input! {
    n : usize,
    s: [String;n],
  }
  let mut num_ind: Vec<Vec<char>> = vec![];
  let mut num_sort: Vec<Vec<usize>> = vec![vec![];10];
  for i in 0..n {
    let d: Vec<char> = s[i].chars().collect();
    num_ind.push(d);
  }
  for i in 0..n {
    for j in 0..10 {
      let num:usize = num_ind[i][j] as usize - 48;
      num_sort[num].push(j);
    }
  }
  let mut ans = std::usize::MAX;
  for i in 0..10 {
    num_sort[i].sort();
    let mut c = vec![0; 10];
    let mut last = vec![0; 10];
    let mut tmp = 0;
    for j in 0..n {
      c[num_sort[i][j]] += 1;
      last[num_sort[i][j]] = num_sort[i][j];
    }
    for j in 0..10 {
      if c[j] == 0 {continue;}
      tmp = tmp.max((c[j] -1) * 10 + last[j]);
    }
    if ans > tmp {
      ans = tmp;
    }
  }
  println!("{}", ans);
}


