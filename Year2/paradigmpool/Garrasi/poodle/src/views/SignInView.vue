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
                    <h1 class="mb-2">Sign In</h1>
                    <h3 class="py-4">Create your Poodle Account</h3>
                    <div class="row">
                      <div class="form-outline form-white mb-4 col-6">
                        <input type="text" id="typeFirstNameX" class="form-control form-control-lg" placeholder="First Name" v-model="data.firstName"/>
                      </div>
                      <div class="form-outline form-white mb-4 col-6">
                        <input type="text" id="typeLastNameX" class="form-control form-control-lg" placeholder="Last Name" v-model="data.lastName"/>
                      </div>
                    </div>
                    <div class="form-outline form-white mb-4">
                      <input type="email" id="typeEmailX" class="form-control form-control-lg" placeholder="Email" v-model="data.email"/>
                    </div>
                    <div class="form-outline form-white mb-4">
                      <input type="password" id="typePasswordX" class="form-control form-control-lg" placeholder="Password" v-model="data.password"/>
                    </div>
                    <div class="form-outline form-white mb-4">
                      <input type="password" id="typePasswordConfirmX" class="form-control form-control-lg" placeholder="Password confirmation" v-model="data.passwordConfirm"/>
                    </div>
                    <div>
                      <a href="/login" style="text-decoration:none; color: blue; float: left;" class="pt-4 px-2">Log In</a>
                      <button class="btn btn-primary px-4 mt-3" style="float: right;" @click="signIn">Next</button>
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

export default {
  name: 'LogIn',
  data () {
    return {
      data: {
        firstName: '',
        lastName: '',
        email: '',
        password: '',
        passwordConfirm: ''
      }
    }
  },
  components: {
    Navbar
  },
  methods: {
    async signIn () {
      if (this.data.password !== this.data.passwordConfirm) {
        console.log('passwords are not the same')
        return
      }
      const response = await fetch('/api/signin', {
        method: 'POST',
        headers: {
          'Content-Type': 'application/json'
        },
        body: JSON.stringify(
          {
            first_name: this.data.firstName,
            last_name: this.data.lastName,
            email: this.data.email,
            password: this.data.password
          }
        )
      })
      console.log(response)
      if (!response.ok) {
        console.log('response is ' + response.status)
      } else {
        this.$router.push({ name: 'login' })
      }
    }
  }
}
</script>
<style scoped>
.header {
    padding-top: 1%;
    padding-bottom: 5%;
}
</style>
