<template>
  <div class="LogIn">
    <Navbar />
    <div class="container mt-5 py-5 h-100">
      <div class="row d-flex justify-content-center align-items-center h-100">
        <div class="col-12 col-md-8 col-lg-6 col-xl-5">
          <div class="card bg-light" style="border-radius: 1rem;">
            <div class="card-body p-5 text-center">
              <div class="mt-md-4 pb-2">
                <img src="../../public/assets/vrai_poodle.png" width="200" alt="Poodle Logo" class="my-3"/>
                <h1 class="mb-2">Login</h1>
                <h3 class="py-4">Use your Poodle Account</h3>
                <div class="form-outline form-white mb-4">
                  <input type="email" id="typeEmailX" class="form-control form-control-lg" placeholder="Email" v-model="data.email" required/>
                </div>
                <div class="form-outline form-white mb-4">
                  <input type="password" id="typePasswordX" class="form-control form-control-lg" placeholder="Password" v-model="data.password" required/>
                </div>
                <div>
                  <a href="/signin" style="text-decoration:none; color: blue; float: left;" class="pt-4 px-2">Create a new account</a>
                  <button class="btn btn-primary px-4 mt-3" style="float: right;" @click="logIn">Next</button>
                </div>
              </div>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>
</template>

<script>
import Navbar from '../components/Menu.vue'
import Cookies from 'js-cookie'

export default {
  name: 'LogIn',
  data () {
    return {
      data: {
        email: '',
        password: ''
      }
    }
  },
  components: {
    Navbar
  },
  created () {
    this.isLog()
  },
  methods: {
    async logIn () {
      console.log(this.data.email)
      console.log(this.data.password)
      const response = await fetch('/api/login', {
        method: 'POST',
        headers: {
          'Content-Type': 'application/json'
        },
        body: JSON.stringify(this.data)
      })
      const data = await response.json()
      console.log(data)
      if (!response.ok) {
        console.error('Cannot login')
      } else {
        Cookies.set('token', data.token)
        Cookies.set('id', data.id)
        this.$router.push({ name: 'index' })
      }
    },
    isLog () {
      console.log('Checking if user is logged')
      if (!(Cookies.get('token') === undefined || Cookies.get('id') === undefined)) {
        console.log('User acess to /account/' + Cookies.get('id'))
        this.$router.push({ name: 'account', params: { id: Cookies.get('id') } })
      }
    }
  }
}
</script>

<style scoped>
.body {
  font-family: 'Product Sans';
}
.header {
  padding-top: 1%;
  padding-bottom: 5%;
}
</style>
