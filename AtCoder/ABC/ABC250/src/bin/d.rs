use proconio::input;

fn main() {
  input! {
    n: i64,
  }
  let sieve = SieveEratosthenes::new(1000000);
  let mut primelist: Vec<i64>= vec![];
  for i in 2..1000001 {
    let d = i as i64;
    if d * d * d <= n && sieve.is_prime(d as usize) {
      primelist.push(d);
    }
  }
  let mut ans = 0;
  let count = |num: i64, index: usize| -> usize {
    if num * 2 > n {return 0;}
    let mut left = 0;
    let mut right = index;
    while left + 1 < right {
      let mid = (left + right) / 2;
      if primelist[mid] <= n / num {
        left = mid;
      } else {
        right = mid;
      }
    }
    right
  };
  for i in 0..primelist.len() {
    ans += count(primelist[i] * primelist[i] * primelist[i], i);
  }
  println!("{}", ans);

}





#[derive(Debug)]
pub struct SieveEratosthenes {
  f: Vec<i64>,
  primes: Vec<i64>,
  n: usize,
}

impl SieveEratosthenes {
  pub fn new(n: usize) -> Self {
    let mut f : Vec<i64> =  vec![0; n+1];
    let mut primes: Vec<i64> = vec![];
    f[0] = -1;
    f[1] = -1;
    for i in 2..n + 1 {
      if f[i] == 0 {
        primes.push(i as i64);
        let mut j = i;
        while j <= n {
          if f[j] == 0 {
            f[j] = i as i64;
          }
          j += i;
        }
      }
    }
    Self { f, primes, n}
  }

  pub fn is_prime(&self, x : usize) -> bool {
    self.f[x] == x as i64
  }

  pub fn factorlist(&self, mut x : usize) -> Vec<i64> {
    assert!(x as usize > 0);
    let mut res = vec![];
    while x > 1 {
      res.push(self.f[x]);
      x /= self.f[x] as usize;
    }
    res
  }

  pub fn factor(&self, x: usize) -> Vec<(i64, i64)> {
    let fl = self.factorlist(x);
    if fl.len() == 0 {return vec![];}
    let mut res = vec![(fl[0], 0); 1];
    for p in fl.iter() {
      let d = res.len();
      if res[d-1].0 == *p {
        res[d-1].1 += 1;
      } else {
        res.push((*p, 1));
      }
    }
    res
  }

  pub fn divisor(&self, x: usize)-> Vec<i64> {
    assert!(x > 0);
    let mut res = vec![1; 1];
    for (prime, ex) in self.factor(x) {
      let n = res.len() * ex as usize;
      for i in 0..n {
        res.push(res[i] * prime);
      }
    }
    res.sort();
    res
  }
}