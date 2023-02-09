import { createApp } from 'vue'
import App from './App.vue'
import router from './router'
// import VueCookie from 'vue-cookies'

// createApp(App).use(Cookies)
createApp(App).use(router).mount('#app')
