---
author: lshmouse
comments: true
date: 2012-01-30 02:05:58+00:00
layout: post
slug: good-algorithm-interview-questions
title: Good Algorithm Interview Questions
tags: [algorithm, interview]
categories:
- algorithm
---


	
  1. First greater number in an array. Given a large array of positive integers, for an arbitrary integer A, we want to know the first integer in the array which is greater than or equal A . O(logn) solution required.

	
  2. For an array of integers, find if there are 3 numbers that add up to zero. An algorithm of complexity O(n^2) was required.

	
  3. Design an algorithm that, given a list of n elements in an array, finds all the elements that appear more than n/3 times in the list.
O(logn) solution required. No hashing/excessive space.

	
  4. Given an array A[], find (i, j) such that A[i] < A[j] and (j - i) is maximum. O(nlogn) solution is ok. O(n) is best.

	
  5. how to find the sorted median of a continuous stream of integers. let the stream is 0,1,2,3,4 the median is 2. now let -2 comes and the median for stream -2,0,1,2,3,4 still the median is 2 or it can be 1. now again -4 comes the median for the stream -4,-2,0,1,2,3,4 is 1. When a new integer come, find the median of the stream in O(logN)


这些问题主要是灵活，举一反三。以后遇到并且自己思考明白的，在更新吧
