import { createRouter, createWebHistory } from 'vue-router'
import IndexView from '../views/IndexView.vue'
import NotesView from '../views/NotesView.vue'
import TopView from '../views/TopView.vue'
import AccountView from '../views/AccountView.vue'
import LogInView from '../views/LogInView.vue'
import SignInView from '../views/SignInView.vue'
import ErrorView from '../views/ErrorView.vue'

const routes = [
  {
    path: '/',
    name: 'index',
    component: IndexView
  },
  {
    path: '/notes/:url',
    name: 'notes',
    component: NotesView
  },
  {
    path: '/top',
    name: 'top',
    component: TopView
  },
  {
    path: '/account/:id',
    name: 'account',
    component: AccountView
  },
  {
    path: '/login',
    name: 'login',
    component: LogInView
  },
  {
    path: '/signin',
    name: 'signin',
    component: SignInView
  },
  {
    path: '/error',
    name: 'error',
    component: ErrorView
  }
]

const router = createRouter({
  history: createWebHistory(process.env.BASE_URL),
  routes
})

export default router
