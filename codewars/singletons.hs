{-# LANGUAGE NoImplicitPrelude, GADTs , DataKinds, TypeFamilies, TypeOperators, RankNTypes, DeriveFunctor #-}

module Singletons where

import Prelude hiding (drop, take, head, tail, index, zipWith, replicate, map, (++))

data Vec a n where
  VNil :: Vec a Zero
  VCons :: a -> Vec a n -> Vec a (Succ n)

-- promoted to type level by data kinds
data Nat = Zero | Succ Nat

data SNat a where
  SZero :: SNat Zero
  SSucc :: SNat a -> SNat (Succ a)

type family (a :: Nat) :< (b :: Nat) :: Bool
type instance m :< Zero = False
type instance Zero :< Succ n = True
type instance (Succ m) :< (Succ n) = m :< n

type family (Add (a :: Nat) (b :: Nat)) :: Nat
type instance (Add Zero b) = b
type instance (Add (Succ a) b) = Succ (Add a b)

type family (Minus (a :: Nat) (b :: Nat)) :: Nat
type instance (Minus a Zero) = a
type instance (Minus Zero a) = Zero
type instance (Minus (Succ a) (Succ b)) = Minus a b

type family (Min (a :: Nat) (b :: Nat)) :: Nat
type instance (Min a Zero) = Zero
type instance (Min Zero b) = Zero
type instance (Min (Succ a) (Succ b)) = Succ (Min a b)

map :: (a -> b) -> Vec a n -> Vec b n
map f VNil = VNil
map f (VCons x xs) = VCons (f x) (map f xs)

index :: ((a :< b) ~ True) => SNat a -> Vec s b -> s
index SZero (VCons v _) = v
index (SSucc a) (VCons _ s) = index a s

replicate :: s -> SNat a -> Vec s a
replicate _ SZero = VNil
replicate s (SSucc n) = VCons s $ replicate s n

-- Both vectors must be of equal length
zipWith :: (a -> b -> c) -> Vec a n -> Vec b n -> Vec c n
zipWith f VNil VNil = VNil
zipWith f (VCons a as) (VCons b bs) = VCons (f a b) $ zipWith f as bs

(++) :: Vec v m -> Vec v n -> Vec v (Add m n)
VNil ++ b = b
(VCons x s) ++ b = VCons x $ s ++ b

-- The semantics should match that of take for normal lists.
take :: SNat l -> Vec a n -> Vec a (Min l n)
take _ VNil = VNil
take SZero _ = VNil
take (SSucc l) (VCons x s) = VCons x $ take l s

-- The semantics should match that of drop for normal lists.
drop :: SNat l -> Vec a n -> Vec a (Minus n l)
drop _ VNil = VNil
drop SZero v = v
drop (SSucc n) (VCons _ s) = drop n s

head :: Vec a (Succ n) -> a
head (VCons v _) = v

tail :: Vec a (Succ n) -> Vec a n
tail (VCons _ v) = v
