package main

import (
	"fmt"
	"math/rand"
	"net/http"
	"time"

	"github.com/prometheus/client_golang/prometheus"
	"github.com/prometheus/client_golang/prometheus/promhttp"
)

var (
	requestsTotal = prometheus.NewCounter(
		prometheus.CounterOpts{
			Name: "requests_total",
			Help: "Total number of requests",
		},
	)

	requestDurationSeconds = prometheus.NewHistogram(
		prometheus.HistogramOpts{
			Name:    "request_duration_seconds",
			Help:    "Duration of requests in seconds",
			Buckets: prometheus.DefBuckets,
		},
	)
)

func init() {
	prometheus.MustRegister(requestsTotal)
	prometheus.MustRegister(requestDurationSeconds)
}

func main() {
	http.Handle("/metrics", promhttp.Handler())
    http.HandleFunc("/api", func(w http.ResponseWriter, r *http.Request) {
        requestsTotal.Inc()

        duration := time.Duration(rand.Intn(1000)) * time.Millisecond
        time.Sleep(duration)

        requestDurationSeconds.Observe(duration.Seconds())

        fmt.Fprintf(w, "Request processed in %v\n", duration)
    })

	fmt.Println("Starting server at 127.0.0.1:8080.")
	http.ListenAndServe(":8080", nil)
}
