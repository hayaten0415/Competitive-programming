use proconio::input;

fn main() {
  input! {
    n: usize,
    a: usize,
    b: usize,
  }
  let mut pe = ".";
  let mut s = "#";
  let mut ans: Vec<String> = Vec::new();
  for i in 0..n * a {
    if i > 0 && i % a == 0 {
      std::mem::swap(&mut pe, &mut s);
    }
    let mut res = String::new();
    for j in 0..n {
      for _ in 0..b {
        if j % 2 == 0 {
          res += pe;
        }else {
          res += s;
        }
      }
    }
    ans.push(res);
  }
  for v in ans.iter() {
    println!("{}", v);
  }
}