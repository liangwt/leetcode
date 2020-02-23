const problems_sidebar = require('./problems_sidebar')
const weekly_contest_sidebar = require('./weekly_contest_sidebar')
const biweekly_contest_sidebar = require('./biweekly_contest_sidebar')

module.exports = {
    title: 'leetcode 精选',
    description: 'Just playing around',
    themeConfig: {
        lastUpdated: 'Last Updated',
        nav: [
            { text: '全部题目', link: '/problems/' },
            { text: '周赛题目', link: '/weekly_contest/' },
            { text: '双周赛题目', link: '/biweekly_contest/' },
            { text: '我的博客', link: 'https://blog.showthink.cn/', target: '_blank' },
            { text: 'GitHub', link: 'https://github.com/liangwt/leetcode', target: '_blank' }
        ],
        sidebar: {
            '/problems/': problems_sidebar,
            '/weekly_contest/': weekly_contest_sidebar,
            '/biweekly_contest/': biweekly_contest_sidebar,
        }
    }
}