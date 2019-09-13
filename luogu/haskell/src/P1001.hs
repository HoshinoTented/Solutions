module P1001 where

data Nat = Zero | Succ Nat

fromNat :: Nat -> Int
fromNat Zero = 0
fromNat (Succ n) = 1 + fromNat n

toNat :: Int -> Nat
toNat 0 = Zero
toNat n = Succ (toNat $ n - 1)

instance Num Nat where
  Zero + n = n
  (Succ a) + b = Succ (a + b)

  Zero - n = Zero
  n - Zero = n
  (Succ a) - (Succ b) = a - b

main :: IO ()
main = do
  [a, b] <- map read . words <$> getLine

  print $ fromNat $ toNat a + toNat b
