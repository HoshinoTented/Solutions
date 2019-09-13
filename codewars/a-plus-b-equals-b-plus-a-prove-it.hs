{-# LANGUAGE GADTs,  TypeFamilies, TypeOperators #-}

module Kata.AdditionCommutes
    ( plusCommutes ) where

import Kata.AdditionCommutes.Definitions
  ( Z, S
  , Natural(..), Equal(..)
  , (:+:))

-- These are some lemmas that may be helpful.
-- They will *not* be tested, so rename them
-- if you so desire. Good luck!

-- | For any n, n = n.
reflexive :: Natural n -> Equal n n
reflexive NumZ = EqlZ
reflexive (NumS n) = EqlS (reflexive n)

-- | if a = b, then b = a.
symmetric :: Equal a b -> Equal b a
symmetric EqlZ = EqlZ
symmetric (EqlS e) = EqlS (symmetric e)

-- | if a = b and b = c, then a = c.
transitive :: Equal a b -> Equal b c -> Equal a c
transitive EqlZ EqlZ = EqlZ
transitive (EqlS ab) (EqlS bc) = EqlS (transitive ab bc)

-- This is the proof that the kata requires.
-- | a + b = b + a
plusCommutes :: Natural a -> Natural b -> Equal (a :+: b) (b :+: a)
plusCommutes = undefined

