# Linux Guru Challenge Assignment 1 - COMP 206 - Fall 2024

Due: Thursday, 24 October, 11:59pm

The Guru challenges in this course are meant to push you to learn new things.
These challenges are graded personally by the instructor on a pass/fail basis.
Recall that completing challenges awards a modest bonus boost to your final course grade:

| Number of challenges completed | Bonus awarded |
| ------------------------------ | ------------- |
|                              1 |             0 |
|                              2 |           0.5 |
|                              3 |             1 |
|                              4 |           1.5 |

## Reading the news

A popular source of tech news is [HackerNews](https://news.ycombinator.com/).
In this challenge, you will be doing [web scraping](https://en.wikipedia.org/wiki/Web_scraping) on
that site.

The reason that the front page of HN is a good candidate for web scraping is that the site:

1. is statically generated. Simply run `curl https://news.ycombinator.com/` and you will be able to
   see in the returned HTML content all the relevant information about the posts.
   This is in contrast with sites chock-full of JavaScript that dynamically load the content of the
   page.
2. does not require authentication to view.

First, some required coding lore reading: [https://stackoverflow.com/questions/1732348/regex-match-open-tags-except-xhtml-self-contained-tags][]

The key takeaway is that regex are insufficent for parsing HTML _in general_. However, since the
HTML of the front page of HN is structured in a particular way, we can get away with it.

**Your task** is to write a bash script, to be run as `./news [PAGE]` to download a page of HN and
produce CSV on stdout with the following columns:

- the current rank of the post
  (this is the number that appears to the left of the arrow in the page next ot the post title)
- number of upvotes on the post
- username of poster
- timestamp for when the post was made
- the post title
- URL of the post

This information is all embedded in the HTML content of the page.

The PAGE parameter of `news` specifies which page of HN to download: notice how the the URL changes
when you go to the bottom of the page and click "more". The PAGE parameter is optional, and
defaults to `1`.

The expectation is that you accomplish this task using `curl`, and plenty of regex.

Good luck, and have fun!

## Submission instructions

This assignment will be submitted following the usual method in this course. The difference is that
instead of naming the directory `hwN`, it should be named `guru1`.

Specifically, your script `news` should be inside the directory
`~/fall2024-comp206/assignments/guru1`.
