<template>
  <div class="menu">
    <nav class="navbar bg-white fixed-top">
      <div class="container-fluid">
        <a href="/login"><img id="menu" src="../../../front/images/profile.webp" width="50" alt="Menu" v-on:click="$router.push({ name: 'index' })"></a>
        <button class="navbar-toggler" type="button" data-bs-toggle="offcanvas" data-bs-target="#offcanvasNavbar">
          <span class="navbar-toggler-icon"></span>
        </button>
        <div class="offcanvas offcanvas-end" tabindex="-1" id="offcanvasNavbar" aria-labelledby="offcanvasNavbarLabel">
          <div class="offcanvas-header">
            <img src="../../public/assets/vrai_poodle.png" width="100" alt="Poodle Logo" class="offcanvas-title" id="offcanvasNavbarLabel"/>
            <button type="button" class="btn-close" data-bs-dismiss="offcanvas" aria-label="Close"></button>
          </div>
          <div class="offcanvas-body">
            <ul class="navbar-nav justify-content-end flex-grow-1 pe-3">
              <li class="nav-item">
                <a class="nav-link" aria-current="page" href="/">Search</a>
              </li>
              <li class="nav-item">
                <a class="nav-link" href="/top">Most disliked topic</a>
              </li>
              <li class="nav-item">
                <a class="nav-link" href="/login" @click="logout()">Logout</a>
              </li>
            </ul>
          </div>
        </div>
      </div>
    </nav>
  </div>
</template>

<script>
import Cookies from 'js-cookie'

export default {
  name: 'HelloWorld',
  methods: {
    logout () {
      Cookies.remove('token')
      Cookies.remove('id')
    }
  }
}
</script>
