// Next.js API route support: https://nextjs.org/docs/api-routes/introduction
import cors from 'cors'
import type { NextApiRequest, NextApiResponse } from 'next'
import nextConnect from 'next-connect'

const handler = nextConnect<NextApiRequest, NextApiResponse>({
  onNoMatch: (req, res) => {
    res.status(404).end('Resource not found!')
  },
  onError: (err, req, res, next) => {
    console.error(err.stack)
    res.status(500).end('Something broke!')
  }
})
  .use(cors())
  .post((req, res) => {
    const { NumeroSocial, RIF, NIT, DIV, Marca = 'Bematech' } = req.body

    return res.status(200).json({ key: 'generatedKey', data: new Date() })
  })

export default handler