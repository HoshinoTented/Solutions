module Codewars.Kata.Permutations (permutations) where

import qualified Data.Vector as V
import Data.Vector ((!), (//))
-- import qualified Data.Vector.Mutable as MV

type Vector = V.Vector
-- type MVector = MV.MVector GHC.Prim.RealWorld String

permutations' :: Int -> Vector Bool -> Vector Char -> [String]
permutations' sum visited str
  | sum == V.length str = [[]]
  | otherwise = [0..V.length str - 1] >>=
    (\i -> (permutations' (sum + 1) (visited // [(i, True)]) str) >>=
      (\s -> [(str ! i) : s]))

permutations :: String -> [String]
permutations xs = let str = V.fromList xs in
  permutations' 0 (V.replicate (V.length str) False) str
