module P3367 where

import qualified Data.Vector.Unboxed as V
import Data.Vector.Unboxed ((!), (//))

type UnionFind = V.Vector Int

ask :: UnionFind -> Int -> (UnionFind, Int)
ask vec i = if vec ! i == i then (vec, i) else 
    let (vec', result) = ask vec $ vec ! i in
        (vec' // [(i, result)], result)

cat :: UnionFind -> Int -> Int -> UnionFind
cat vec x y = let (vec', x') = ask vec x in
    let (vec'', y') = ask vec' y in
        vec // [(x', y')]

resolve :: Int -> UnionFind -> IO ()
resolve 0 _ = return ()
resolve n uf = do
    [z, x, y] <- map read . words <$> getLine :: IO [Int]

    uf' <- if z == 1 then return $ cat uf x y else 
        let (vec, x') = ask uf x
            (vec', y') = ask vec y in 
            putStrLn (if x' == y' then "Y" else "N") >>= const (return vec')

    resolve (n - 1) uf'

main :: IO ()
main = do
    [n, m] <- map read . words <$> getLine :: IO [Int]

    resolve m $ V.generate (n + 1) id

    return ()