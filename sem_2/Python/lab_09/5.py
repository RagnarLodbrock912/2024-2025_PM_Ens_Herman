import numpy as np
from numpy.linalg import slogdet, inv
from scipy.stats import multivariate_normal
import time

def logpdf_manual(X, m, C):
    N, D = X.shape
    X_centered = X - m
    C_inv = inv(C)
    sign, logdet = slogdet(C)
    if sign != 1:
        raise ValueError("Covariance matrix must be positive definite")
    quad_form = np.sum(X_centered @ C_inv * X_centered, axis=1)
    return -0.5 * (D * np.log(2 * np.pi) + logdet + quad_form)

np.random.seed(0)
N, D = 1000, 5
X = np.random.randn(N, D)
m = np.random.randn(D)
C = np.cov(X, rowvar=False) + np.eye(D) * 1e-3

manual_logpdf = logpdf_manual(X, m, C)
scipy_logpdf = multivariate_normal(m, C).logpdf(X)

print("Max abs diff:", np.max(np.abs(manual_logpdf - scipy_logpdf)))

start_manual = time.time()
logpdf_manual(X, m, C)
end_manual = time.time()

start_scipy = time.time()
multivariate_normal(m, C).logpdf(X)
end_scipy = time.time()

print(f"Manual time: {end_manual - start_manual:.6f}")
print(f"Scipy time:  {end_scipy - start_scipy:.6f}")
